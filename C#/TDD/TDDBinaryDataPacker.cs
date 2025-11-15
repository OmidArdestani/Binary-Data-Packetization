using System.IO.Compression;
using System.Linq;
using System.Text;

namespace BinaryDataPacker.Tests;

[TestClass]
public sealed class BinaryDataPackerTdd
{
    private static readonly byte[] SamplePayload = Encoding.UTF8.GetBytes("binary-data-packet");

    [TestMethod]
    public void RoundTripWithConstantMarkersAndChecksum()
    {
        var packer = new BinaryDataPacker.BinaryDataPacker();
        packer.AddSOFBuilder(new ConstantHeaderBuilder(Encoding.ASCII.GetBytes("HDR")));
        packer.AddEOFBuilder(new ConstantHeaderBuilder(Encoding.ASCII.GetBytes("FTR")));
        packer.AddEOFBuilder(new Crc32Builder());

        var packet = packer.GetPacket(SamplePayload);
        Assert.IsTrue(packet.AsSpan(0, 3).SequenceEqual(Encoding.ASCII.GetBytes("HDR")));
        Assert.IsTrue(packet.AsSpan(packet.Length - 7, 3).SequenceEqual(Encoding.ASCII.GetBytes("FTR")));

        var unpacked = packer.UnpackData(packet);
        CollectionAssert.AreEqual(SamplePayload, unpacked);
    }

    [TestMethod]
    public void DetectsTamperedLength()
    {
        var packer = new BinaryDataPacker.BinaryDataPacker();
        packer.AddSOFBuilder(new PayloadLengthBuilder());

        var packet = packer.GetPacket(SamplePayload);
        var tampered = (byte[])packet.Clone();
        tampered[0] ^= 0x01;

        Assert.ThrowsException<PacketValidationException>(() => packer.UnpackData(tampered));
    }

    [TestMethod]
    public void SupportsTransformations()
    {
        var packer = new BinaryDataPacker.BinaryDataPacker();
        packer.AddPacketBuilder(new XorPacketBuilder(Encoding.ASCII.GetBytes("key")));
        packer.AddPacketBuilder(new DeflatePacketBuilder(CompressionLevel.Fastest));

        packer.AddEOFBuilder(new Crc32Builder());

        var packet = packer.GetPacket(SamplePayload);
        Assert.IsTrue(packet.Length > SamplePayload.Length); // includes metadata

        var unpacked = packer.UnpackData(packet);
        CollectionAssert.AreEqual(SamplePayload, unpacked);
    }
}

