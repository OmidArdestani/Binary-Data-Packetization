#ifndef CBINARYDATAPACKER_H
#define CBINARYDATAPACKER_H

#include <QObject>


#include "HeaderBuilders/ConstHeader.h"
#include "HeaderBuilders/ValidationHeader/Checksum.h"
#include "HeaderBuilders/ValidationHeader/CRC8.h"
#include "HeaderBuilders/ValidationHeader/CRC16.h"
#include "HeaderBuilders/ValidationHeader/CRC32.h"
#include "HeaderBuilders/ValidationHeader/CRC64.h"
#include "HeaderBuilders/ValidationHeader/Hash.h"
#include "HeaderBuilders/ValidationHeader/XOR.h"

#include "PacketBuilders/Compressors/Arithmetic.h"
#include "PacketBuilders/Compressors/DEFLATE.h"
#include "PacketBuilders/Compressors/Huffman.h"
#include "PacketBuilders/Compressors/JPEG.h"

#include "PacketBuilders/Encryptions/RSA.h"
#include "PacketBuilders/Encryptions/AES.h"
#include "PacketBuilders/Encryptions/DES.h"
#include "PacketBuilders/Encryptions/TwoFish.h"


class CBinaryDataPacker
{
public:
    CBinaryDataPacker(){}

    void AddPacketBuilder(IPacketBuilder* packet_builder);
    void AddSOFBuilder(IHeaderBuilder* header_builder);
    void AddEOFBuilder(IHeaderBuilder* header_builder);
    void GetPacket(const char* raw_data,int size,char* result_buffer,int& result_size);
    void UnpackData(const char* packed_data, int packet_size,char* result_buffer,int& result_size);

private:
    std::list<IHeaderBuilder*> SOFs;
    std::list<IHeaderBuilder*> EOFs;
    std::list<IPacketBuilder*> PacketBuilders;
};
#endif
