#include "DES.h"
#include <cstring>
#include <vector>

using namespace PacketBuilder::Encryption;

CDES::CDES():IPacketBuilder()
{

}

uint64_t CDES::permute(uint64_t input, const int *table, int size)
{
    uint64_t output = 0;
    for (int i = 0; i < size; i++)
    {
        output <<= 1;
        output |= (input >> (64 - table[i])) & 1;
    }
    return output;
}

uint32_t CDES::feistel(uint32_t halfBlock, uint64_t subKey)
{
    return (halfBlock ^ subKey) & 0xFFFFFFFF;
}

uint64_t CDES::desEncryptBlock(uint64_t plaintext)
{
    uint64_t permutedInput = permute(plaintext, IP, 64);
    uint32_t left = permutedInput >> 32;
    uint32_t right = permutedInput & 0xFFFFFFFF;

    // Single round Feistel function (DES has 16 rounds)
    uint32_t newRight = left ^ feistel(right, key);
    uint32_t newLeft = right;

    uint64_t combined = ((uint64_t)newLeft << 32) | newRight;
    return permute(combined, FP, 64);
}

uint64_t CDES::desDecryptBlock(uint64_t ciphertext)
{
    return desEncryptBlock(ciphertext); // Same operation (simplified)
}

void CDES::PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size)
{
    // Calculate how many blocks are needed (8-byte blocks)
    packed_size = ((raw_data_size + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE;
    packed_data = new char[packed_size];

    for (int i = 0; i < packed_size; i += BLOCK_SIZE)
    {
        uint64_t block = 0;
        std::memcpy(&block, raw_data + i, std::min(BLOCK_SIZE, raw_data_size - i));

        // Encrypt block
        uint64_t encryptedBlock = desEncryptBlock(block);
        std::memcpy(packed_data + i, &encryptedBlock, BLOCK_SIZE);
    }
}

void CDES::UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size)
{
    unpacked_size = size;  // DES block size remains the same
    unpacked_data = new char[unpacked_size];

    for (int i = 0; i < size; i += BLOCK_SIZE)
    {
        uint64_t block = 0;
        std::memcpy(&block, packed_data + i, BLOCK_SIZE);

        // Decrypt block
        uint64_t decryptedBlock = desDecryptBlock(block);
        std::memcpy(unpacked_data + i, &decryptedBlock, BLOCK_SIZE);
    }
}
