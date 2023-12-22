
namespace BinaryDataPacker
{
    public interface IHeaderBuilder { }
    public interface IPacketBuilder { }

    namespace HeaderBuilder
    {
        public class ConstHeader:IHeaderBuilder { }

        namespace ValidationHeader
        {
            public class Checksum : IHeaderBuilder { }
            public class CRC8 : IHeaderBuilder { }
            public class CRC16 : IHeaderBuilder { }
            public class CRC32 : IHeaderBuilder { }
            public class CRC64 : IHeaderBuilder { }
            public class Hash : IHeaderBuilder { }
            public class XOr : IHeaderBuilder { }
        }
    }

    namespace PacketBuilder
    {
        namespace Encryption
        {
            public class RSA:IPacketBuilder{ }
            public class DES : IPacketBuilder { }
            public class AES : IPacketBuilder { }
            public class TwoFish : IPacketBuilder { }
        }
        namespace Compressor
        {
            public class DEFLATE : IPacketBuilder { }
            public class Huffman : IPacketBuilder { }
            public class Arithmetic : IPacketBuilder { }
            public class JPEG : IPacketBuilder { }
        }
    }


    public class BinaryDataPacker
    {
        public BinaryDataPacker() { }

        public void AddPacketBuilder(IPacketBuilder packet_builder) { }
        public void AddSOFBuilder(IHeaderBuilder header_builder) { }
        public void AddEOFBuilder(IHeaderBuilder header_builder) { }
        public void GetPacket(byte[] raw_data, int size, ref byte[] result_buffer, ref int result_size) { }
        public void UnpackData(byte[] packed_data, int packet_size, ref byte[] result_buffer, ref int result_size) { }
    };
}
