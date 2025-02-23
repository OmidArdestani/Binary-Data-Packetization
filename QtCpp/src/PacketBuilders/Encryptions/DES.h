
#pragma once

#include <PacketBuilders/PacketBuilder.h>
#include <iostream>

namespace PacketBuilder{
namespace Encryption{
class CDES:public IPacketBuilder
{
public:
    CDES();

    // IPacketBuilder interface
public:
    void PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size) override;
    void UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size) override;
    EBodyType GetType() override{return EBodyType::EncDes;}

private:
    // DES Initial Permutation Table
    const int IP[64] = {
        58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
    };

    // DES Final Permutation Table
    const int FP[64] = {
        40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
    };
    const int BLOCK_SIZE = 8;  // DES uses 64-bit (8-byte) blocks
    uint64_t key = 0x133457799BBCDFF1; // 64-bit DES key (only 56 bits are used)

private:
    uint64_t permute(uint64_t input, const int *table, int size);
    uint32_t feistel(uint32_t halfBlock, uint64_t subKey);
    uint64_t desEncryptBlock(uint64_t plaintext);
    uint64_t desDecryptBlock(uint64_t ciphertext);
};
}
}

