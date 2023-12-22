using System.Reflection.PortableExecutable;
using System.Runtime.Intrinsics.Arm;
using System.Text;

namespace BinaryDataPacker
{
    [TestClass]
    public class TDDBinaryDataPacker
    {
        private static readonly byte[] RawData = Encoding.UTF8.GetBytes("this is a message for packaging test.");
        private static readonly int RawDataSize = RawData.Length;

        BinaryDataPacker BuildPacker(IHeaderBuilder header, IPacketBuilder body, IHeaderBuilder footer)
        {
            BinaryDataPacker bdp = new BinaryDataPacker();
            bdp.AddSOFBuilder(header);
            bdp.AddPacketBuilder(body);
            bdp.AddEOFBuilder(footer);
            return bdp;
        }

        [TestMethod]
        public void VerifyResult(BinaryDataPacker bdp)
        {
            byte[] packet_to_send = null;
            int packet_size = -1;
            bdp.GetPacket(RawData, RawDataSize, ref packet_to_send, ref packet_size);

            Assert.Equals(packet_size, 0); // check the size greater than 0

            byte[] unpacked_data = null;
            int unpacked_data_size = -1;
            bdp.UnpackData(packet_to_send, packet_size, ref unpacked_data, ref unpacked_data_size);

            Assert.Equals(unpacked_data_size, RawDataSize);

            // Compare the strings using QCOMPARE
            Assert.Equals(RawData, unpacked_data);
        }

        // ------------------------------------
        //The test method name strcuture is (HeaderBuilderName_PacketBuilderName_FooterBuilderName)
        // ------------------------------------
        [TestMethod]
        public void Const_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Const_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Const_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Const_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Const_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Const_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Const_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Const_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Const_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ConstHeader(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Checksum_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Checksum_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Checksum_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Checksum_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Checksum_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Checksum_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Checksum_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Checksum_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Checksum(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC8_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC8_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC8_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC8_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC8_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC8_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC8_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC8_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC8(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC16_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC16_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC16_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC16_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC16_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC16_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC16_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC16_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC16(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC32_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC32_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC32_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC32_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC32_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC32_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC32_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC32_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC32(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void CRC64_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void CRC64_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void CRC64_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void CRC64_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void CRC64_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void CRC64_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void CRC64_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void CRC64_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.CRC64(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void XOr_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void XOr_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void XOr_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void XOr_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void XOr_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void XOr_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void XOr_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void XOr_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.XOr(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_RSA_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_RSA_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_RSA_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_RSA_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_RSA_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_RSA_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_RSA_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_RSA_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.RSA(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_AES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_AES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_AES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_AES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_AES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_AES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_AES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_AES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.AES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_DES_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_DES_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_DES_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_DES_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_DES_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_DES_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_DES_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_DES_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.DES(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_TwoFish_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_TwoFish_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_TwoFish_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_TwoFish_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_TwoFish_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_TwoFish_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_TwoFish_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_TwoFish_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Encryption.TwoFish(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_DEFLATE_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_DEFLATE_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_DEFLATE_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_DEFLATE_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_DEFLATE_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_DEFLATE_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_DEFLATE_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_DEFLATE_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.DEFLATE(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_Huffman_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_Huffman_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_Huffman_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_Huffman_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_Huffman_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_Huffman_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_Huffman_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_Huffman_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Huffman(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_Arithmetic_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_Arithmetic_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_Arithmetic_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_Arithmetic_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_Arithmetic_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_Arithmetic_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_Arithmetic_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_Arithmetic_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.Arithmetic(), new HeaderBuilder.ValidationHeader.Hash()));
        }
        [TestMethod]
        public void Hash_JPEG_ConstHeader()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ConstHeader()));
        }
        [TestMethod]
        public void Hash_JPEG_Checksum()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Checksum()));
        }
        [TestMethod]
        public void Hash_JPEG_CRC8()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC8()));
        }
        [TestMethod]
        public void Hash_JPEG_CRC16()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC16()));
        }
        [TestMethod]
        public void Hash_JPEG_CRC32()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC32()));
        }
        [TestMethod]
        public void Hash_JPEG_CRC64()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.CRC64()));
        }
        [TestMethod]
        public void Hash_JPEG_XOr()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.XOr()));
        }
        [TestMethod]
        public void Hash_JPEG_Hash()
        {
            VerifyResult(BuildPacker(new HeaderBuilder.ValidationHeader.Hash(), new PacketBuilder.Compressor.JPEG(), new HeaderBuilder.ValidationHeader.Hash()));
        }
    }
}