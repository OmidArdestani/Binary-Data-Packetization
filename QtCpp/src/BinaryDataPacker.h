#pragma once

#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QtEndian>
#include <QtCore/QString>

#include <functional>
#include <stdexcept>

namespace BinaryDataPacker
{

class PacketConfigurationError : public std::logic_error
{
public:
    explicit PacketConfigurationError(const QString &message)
        : std::logic_error(message.toStdString())
    {
    }
};

class PacketValidationError : public std::runtime_error
{
public:
    explicit PacketValidationError(const QString &message)
        : std::runtime_error(message.toStdString())
    {
    }
};

using Validator = std::function<void(const QByteArray &)>;

class IHeaderBuilder
{
public:
    virtual ~IHeaderBuilder() = default;

    virtual int size() const = 0;
    virtual QByteArray build(const QByteArray &rawPayload) const = 0;
    virtual Validator createValidator(const QByteArray &builtBytes) const = 0;
};

class IPacketBuilder
{
public:
    virtual ~IPacketBuilder() = default;

    virtual QByteArray apply(const QByteArray &data) const = 0;
    virtual QByteArray revert(const QByteArray &data) const = 0;
};

namespace HeaderBuilder
{

class ConstantBuilder final : public IHeaderBuilder
{
public:
    explicit ConstantBuilder(const QByteArray &value);

    int size() const override;
    QByteArray build(const QByteArray &rawPayload) const override;
    Validator createValidator(const QByteArray &builtBytes) const override;

private:
    QByteArray m_value;
};

class PayloadLengthBuilder final : public IHeaderBuilder
{
public:
    int size() const override;
    QByteArray build(const QByteArray &rawPayload) const override;
    Validator createValidator(const QByteArray &builtBytes) const override;
};

namespace Validation
{

class Crc32Builder final : public IHeaderBuilder
{
public:
    int size() const override;
    QByteArray build(const QByteArray &rawPayload) const override;
    Validator createValidator(const QByteArray &builtBytes) const override;

private:
    static quint32 calculateCrc32(const QByteArray &data);
};

} // namespace Validation

} // namespace HeaderBuilder

namespace PacketBuilder
{

class XorCipher final : public IPacketBuilder
{
public:
    explicit XorCipher(const QByteArray &key);

    QByteArray apply(const QByteArray &data) const override;
    QByteArray revert(const QByteArray &data) const override;

private:
    QByteArray m_key;
};

class DeflateCompressor final : public IPacketBuilder
{
public:
    explicit DeflateCompressor(int level = 6);

    QByteArray apply(const QByteArray &data) const override;
    QByteArray revert(const QByteArray &data) const override;

private:
    int m_level;
};

} // namespace PacketBuilder

class BinaryDataPacker
{
public:
    BinaryDataPacker() = default;

    void SetSOFBuilder(IHeaderBuilder *builder);
    void AddEOFBuilder(IHeaderBuilder *builder);
    void AddPacketBuilder(IPacketBuilder *builder);

    QByteArray GetPacket(const QByteArray &rawPayload) const;
    QByteArray UnpackPacket(const QByteArray &packet) const;

    void GetPacket(const char *raw_data, int size, char *&result_buffer, int &result_size) const;
    void UnpackData(const char *packed_data, int packet_size, char *&result_buffer, int &result_size) const;

private:
    IHeaderBuilder *m_sofBuilder = nullptr;
    QList<IHeaderBuilder *> m_eofBuilders;
    QList<IPacketBuilder *> m_packetBuilders;
};

} // namespace BinaryDataPacker

