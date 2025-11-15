#include "BinaryDataPacker.h"

#include <QtCore/QVector>
#include <QtCore/qbytearray.h>
#include <QtCore/qglobal.h>
#include <QtCore/QString>

#include <algorithm>
#include <cstring>

using namespace BinaryDataPacker;

// -----------------------------------------------------------------------------
// Header builders

HeaderBuilder::ConstantBuilder::ConstantBuilder(const QByteArray &value)
    : m_value(value)
{
    if (m_value.isEmpty())
    {
        throw PacketConfigurationError(QStringLiteral("constant header value must not be empty"));
    }
}

int HeaderBuilder::ConstantBuilder::size() const
{
    return m_value.size();
}

QByteArray HeaderBuilder::ConstantBuilder::build(const QByteArray &rawPayload) const
{
    Q_UNUSED(rawPayload);
    return m_value;
}

Validator HeaderBuilder::ConstantBuilder::createValidator(const QByteArray &builtBytes) const
{
    if (builtBytes != m_value)
    {
        throw PacketValidationError(QStringLiteral("constant marker mismatch"));
    }

    return [](const QByteArray &) {};
}

int HeaderBuilder::PayloadLengthBuilder::size() const
{
    return 4;
}

QByteArray HeaderBuilder::PayloadLengthBuilder::build(const QByteArray &rawPayload) const
{
    QByteArray result(4, Qt::Uninitialized);
    qToBigEndian<quint32>(static_cast<quint32>(rawPayload.size()), reinterpret_cast<uchar *>(result.data()));
    return result;
}

Validator HeaderBuilder::PayloadLengthBuilder::createValidator(const QByteArray &builtBytes) const
{
    if (builtBytes.size() != 4)
    {
        throw PacketValidationError(QStringLiteral("invalid payload length field size"));
    }

    const auto expectedLength = qFromBigEndian<quint32>(reinterpret_cast<const uchar *>(builtBytes.constData()));
    return [expectedLength](const QByteArray &payload) {
        if (payload.size() != static_cast<int>(expectedLength))
        {
            throw PacketValidationError(QStringLiteral("payload length mismatch"));
        }
    };
}

int HeaderBuilder::Validation::Crc32Builder::size() const
{
    return 4;
}

QByteArray HeaderBuilder::Validation::Crc32Builder::build(const QByteArray &rawPayload) const
{
    const auto crc = calculateCrc32(rawPayload);
    QByteArray result(4, Qt::Uninitialized);
    qToBigEndian<quint32>(crc, reinterpret_cast<uchar *>(result.data()));
    return result;
}

Validator HeaderBuilder::Validation::Crc32Builder::createValidator(const QByteArray &builtBytes) const
{
    if (builtBytes.size() != 4)
    {
        throw PacketValidationError(QStringLiteral("invalid CRC field size"));
    }

    const auto expected = qFromBigEndian<quint32>(reinterpret_cast<const uchar *>(builtBytes.constData()));
    return [expected](const QByteArray &payload) {
        const auto actual = calculateCrc32(payload);
        if (actual != expected)
        {
            throw PacketValidationError(QStringLiteral("CRC mismatch"));
        }
    };
}

quint32 HeaderBuilder::Validation::Crc32Builder::calculateCrc32(const QByteArray &data)
{
    static constexpr quint32 polynomial = 0xEDB88320u;
    quint32 crc = 0xFFFFFFFFu;

    for (auto byte : data)
    {
        crc ^= static_cast<quint8>(byte);
        for (int bit = 0; bit < 8; ++bit)
        {
            const bool lsb = (crc & 1u) != 0u;
            crc >>= 1u;
            if (lsb)
            {
                crc ^= polynomial;
            }
        }
    }

    return crc ^ 0xFFFFFFFFu;
}

// -----------------------------------------------------------------------------
// Packet builders

PacketBuilder::XorCipher::XorCipher(const QByteArray &key)
    : m_key(key)
{
    if (m_key.isEmpty())
    {
        throw PacketConfigurationError(QStringLiteral("XOR key must not be empty"));
    }
}

QByteArray PacketBuilder::XorCipher::apply(const QByteArray &data) const
{
    QByteArray result(data);
    for (int i = 0; i < result.size(); ++i)
    {
        result[i] = result.at(i) ^ m_key.at(i % m_key.size());
    }
    return result;
}

QByteArray PacketBuilder::XorCipher::revert(const QByteArray &data) const
{
    return apply(data);
}

PacketBuilder::DeflateCompressor::DeflateCompressor(int level)
    : m_level(std::clamp(level, 0, 9))
{
}

QByteArray PacketBuilder::DeflateCompressor::apply(const QByteArray &data) const
{
    return qCompress(data, m_level);
}

QByteArray PacketBuilder::DeflateCompressor::revert(const QByteArray &data) const
{
    const auto result = qUncompress(data);
    if (result.isEmpty() && !data.isEmpty() && data != qCompress(QByteArray()))
    {
        throw PacketValidationError(QStringLiteral("failed to decompress payload"));
    }
    return result;
}

// -----------------------------------------------------------------------------
// BinaryDataPacker

void BinaryDataPacker::SetSOFBuilder(IHeaderBuilder *builder)
{
    if (!builder)
    {
        throw PacketConfigurationError(QStringLiteral("SOF builder must not be null"));
    }

    m_sofBuilder = builder;
}

void BinaryDataPacker::AddEOFBuilder(IHeaderBuilder *builder)
{
    if (!builder)
    {
        throw PacketConfigurationError(QStringLiteral("EOF builder must not be null"));
    }

    m_eofBuilders.append(builder);
}

void BinaryDataPacker::AddPacketBuilder(IPacketBuilder *builder)
{
    if (!builder)
    {
        throw PacketConfigurationError(QStringLiteral("packet builder must not be null"));
    }

    m_packetBuilders.append(builder);
}

QByteArray BinaryDataPacker::GetPacket(const QByteArray &rawPayload) const
{
    if (rawPayload.isNull())
    {
        throw PacketConfigurationError(QStringLiteral("raw payload must not be null"));
    }

    QVector<Validator> validators;
    validators.reserve(1 + m_eofBuilders.size());

    QByteArray header;
    if (m_sofBuilder)
    {
        header = m_sofBuilder->build(rawPayload);
        if (header.size() != m_sofBuilder->size())
        {
            throw PacketConfigurationError(QStringLiteral("SOF builder returned unexpected number of bytes"));
        }
        validators.append(m_sofBuilder->createValidator(header));
    }

    QByteArray footer;
    for (auto *builder : m_eofBuilders)
    {
        const auto segment = builder->build(rawPayload);
        if (segment.size() != builder->size())
        {
            throw PacketConfigurationError(QStringLiteral("EOF builder returned unexpected number of bytes"));
        }
        footer.append(segment);
        validators.append(builder->createValidator(segment));
    }

    QByteArray transformed = rawPayload;
    for (auto *builder : m_packetBuilders)
    {
        transformed = builder->apply(transformed);
    }

    QByteArray packet;
    packet.reserve(header.size() + 4 + transformed.size() + footer.size());
    packet.append(header);

    QByteArray lengthField(4, Qt::Uninitialized);
    qToBigEndian<quint32>(static_cast<quint32>(transformed.size()), reinterpret_cast<uchar *>(lengthField.data()));
    packet.append(lengthField);

    packet.append(transformed);
    packet.append(footer);

    for (const auto &validator : validators)
    {
        validator(rawPayload);
    }

    return packet;
}

QByteArray BinaryDataPacker::UnpackPacket(const QByteArray &packet) const
{
    if (packet.isNull())
    {
        throw PacketValidationError(QStringLiteral("packet must not be null"));
    }

    QVector<Validator> validators;
    QByteArray working = packet;

    if (m_sofBuilder)
    {
        if (working.size() < m_sofBuilder->size())
        {
            throw PacketValidationError(QStringLiteral("packet is too small to contain the header"));
        }
        const auto header = working.left(m_sofBuilder->size());
        validators.append(m_sofBuilder->createValidator(header));
        working.remove(0, m_sofBuilder->size());
    }

    QVector<Validator> footerValidators;
    if (!m_eofBuilders.isEmpty())
    {
        footerValidators.reserve(m_eofBuilders.size());
        for (int index = m_eofBuilders.size() - 1; index >= 0; --index)
        {
            auto *builder = m_eofBuilders.at(index);
            if (working.size() < builder->size())
            {
                throw PacketValidationError(QStringLiteral("packet is too small to contain the footer"));
            }
            const auto segment = working.right(builder->size());
            footerValidators.prepend(builder->createValidator(segment));
            working.chop(builder->size());
        }
    }

    for (const auto &validator : footerValidators)
    {
        validators.append(validator);
    }

    if (working.size() < 4)
    {
        throw PacketValidationError(QStringLiteral("packet does not contain body length information"));
    }

    const auto declaredLength = qFromBigEndian<quint32>(reinterpret_cast<const uchar *>(working.constData()));
    working.remove(0, 4);

    if (working.size() != static_cast<int>(declaredLength))
    {
        throw PacketValidationError(QStringLiteral("body length mismatch"));
    }

    QByteArray transformed = working;
    for (int index = m_packetBuilders.size() - 1; index >= 0; --index)
    {
        transformed = m_packetBuilders.at(index)->revert(transformed);
    }

    for (const auto &validator : validators)
    {
        validator(transformed);
    }

    return transformed;
}

void BinaryDataPacker::GetPacket(const char *raw_data, int size, char *&result_buffer, int &result_size) const
{
    if (!raw_data || size < 0)
    {
        throw PacketConfigurationError(QStringLiteral("invalid raw payload"));
    }

    const QByteArray payload(raw_data, size);
    const auto packet = GetPacket(payload);
    result_size = packet.size();
    auto *buffer = new char[result_size];
    std::memcpy(buffer, packet.constData(), result_size);
    result_buffer = buffer;
}

void BinaryDataPacker::UnpackData(const char *packed_data, int packet_size, char *&result_buffer, int &result_size) const
{
    if (!packed_data || packet_size < 0)
    {
        throw PacketValidationError(QStringLiteral("invalid packet"));
    }

    const QByteArray packet(packed_data, packet_size);
    const auto payload = UnpackPacket(packet);
    result_size = payload.size();
    auto *buffer = new char[result_size];
    std::memcpy(buffer, payload.constData(), result_size);
    result_buffer = buffer;
}

