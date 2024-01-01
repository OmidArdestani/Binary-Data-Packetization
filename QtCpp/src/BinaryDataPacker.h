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

#define BODY_SIZE_NUMBER_OF_BITS 14
#define MAX_PACKET_SIZE (int)std::pow(2, BODY_SIZE_NUMBER_OF_BITS)

class CBinaryDataPacker
{
public:
    CBinaryDataPacker(){}

    void GetPacket(const char* raw_data,int size,char*& result_buffer,int& result_size);
    void UnpackData(const char* packed_data, int packet_size,char*& result_buffer,int& result_size);
    void AddPacketBuilder(IPacketBuilder* packet_builder);
    void SetSOFBuilder(IHeaderBuilder* header_builder);
    void SetEOFBuilder(IHeaderBuilder* header_builder);

private:
    struct SAdditionalInfo{
        union{
            struct{
                uint8_t SOFHeaderType:3;
                uint16_t BodyTypes:12;
                uint8_t EOFHeaderType:3;
                uint16_t BodySize : BODY_SIZE_NUMBER_OF_BITS;
            };
            uint32_t Value;
        };

        SAdditionalInfo(){Value = 0;}
        void AddBodyType(EBodyType type)
        {
            for(int i=0;i<12;++i)
            {
                if(((BodyTypes>>i)&7) == 1)
                {
                    BodyTypes = (static_cast<int>(type) << i) & 7;
                    return;
                }
            }
        }

        uint8_t GetBodyType(int index)
        {
            return (BodyTypes>>(index * 3)) & 7;
        }

    }AdditionalInfo;

    void InsertAdditionalInfo(const char* body_data, int size, char*& result_buffer, int& result_size);
    void ExtractAdditionalInfo(const char* body_data, int size, char*& result_buffer, int& result_size);

private:
    IHeaderBuilder* SOFHeaderBuilder = nullptr;
    IHeaderBuilder* EOFHeaderBuilder = nullptr;
    std::list<IPacketBuilder*> PacketBuilders;
};
#endif
