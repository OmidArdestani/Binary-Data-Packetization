#include <QtTest/QtTest>

#include <BinaryDataPacker.h>

using namespace BinaryDataPacker;

class TDDBinaryDataPacker final : public QObject
{
    Q_OBJECT

private slots:
    void roundTripWithMarkers();
    void detectsTamperedLength();
    void roundTripWithTransformations();
};

namespace
{
QByteArray samplePayload()
{
    return QByteArrayLiteral("activation:test-payload");
}
} // namespace

void TDDBinaryDataPacker::roundTripWithMarkers()
{
    BinaryDataPacker packer;
    HeaderBuilder::ConstantBuilder header("HDR");
    HeaderBuilder::ConstantBuilder footer("FTR");
    HeaderBuilder::Validation::Crc32Builder crc;

    packer.SetSOFBuilder(&header);
    packer.AddEOFBuilder(&footer);
    packer.AddEOFBuilder(&crc);

    const auto packet = packer.GetPacket(samplePayload());
    QVERIFY(packet.startsWith("HDR"));
    QVERIFY(packet.endsWith(QByteArray("FTR") + crc.build(samplePayload())));

    const auto unpacked = packer.UnpackPacket(packet);
    QCOMPARE(unpacked, samplePayload());
}

void TDDBinaryDataPacker::detectsTamperedLength()
{
    BinaryDataPacker packer;
    HeaderBuilder::PayloadLengthBuilder length;
    packer.SetSOFBuilder(&length);

    auto packet = packer.GetPacket(samplePayload());
    packet[0] ^= 0x01;

    QVERIFY_EXCEPTION_THROWN(packer.UnpackPacket(packet), PacketValidationError);
}

void TDDBinaryDataPacker::roundTripWithTransformations()
{
    BinaryDataPacker packer;
    PacketBuilder::XorCipher xorCipher("key");
    PacketBuilder::DeflateCompressor compressor(3);
    HeaderBuilder::Validation::Crc32Builder crc;

    packer.AddPacketBuilder(&xorCipher);
    packer.AddPacketBuilder(&compressor);
    packer.AddEOFBuilder(&crc);

    const auto packet = packer.GetPacket(samplePayload());
    QVERIFY(packet.size() > samplePayload().size());

    const auto unpacked = packer.UnpackPacket(packet);
    QCOMPARE(unpacked, samplePayload());
}

QTEST_MAIN(TDDBinaryDataPacker)
#include "TDDBinaryDataPacker.moc"

