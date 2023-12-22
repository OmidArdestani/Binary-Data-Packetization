#include <QObject>


class IHeaderBuilder;
class IPacketBuilder;

namespace HeaderBuilder{
    class ConstHeader;

	namespace ValidationHeader{
		class Checksum;
		class CRC8;
		class CRC16;
		class CRC32;
		class CRC64;
		class Hash;
		class XOr;
    }
}

namespace PacketBuilder{
	namespace Encryption{
        class RSA;
		class DES;
		class AES;
		class TwoFish;
    }
	namespace Compressor{
        class DEFLATE;
		class Huffman;
        class Arithmetic;
		class JPEG;
    }
}


class BinaryDataPacker: public QObject
{
public:
	BinaryDataPacker();
	
	void AddPacketBuilder(IPacketBuilder* packet_builder);
	void AddSOFBuilder(IHeaderBuilder* header_builder);
	void AddEOFBuilder(IHeaderBuilder* header_builder);
    void GetPacket(const char* raw_data,int size,char* result_buffer,int& result_size);
    void UnpackData(const char* packed_data, int packet_size,char* result_buffer,int& result_size);
};
