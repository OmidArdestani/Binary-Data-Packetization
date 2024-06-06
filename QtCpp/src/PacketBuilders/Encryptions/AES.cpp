#include "AES.h"
#include <cstdio>
#include <cstring>
#include <stdexcept>

/*******************************
 * This emplimentation comes from SergeyBel.
 * https://github.com/SergeyBel/AES/blob/master/src/AES.cpp
 * ***************************/


PacketBuilder::Encryption::CAES::CAES(const PacketBuilder::Encryption::CAES::EAESKeyLength key_length)
    : IPacketBuilder()
    , AESKeyLength(key_length)
{
    Init();
}

PacketBuilder::Encryption::CAES::CAES(const PacketBuilder::Encryption::CAES::EAESKeyLength key_length, unsigned char key[])
    : IPacketBuilder()
    , AESKeyLength(key_length)
{
    Init();
}

void PacketBuilder::Encryption::CAES::PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size)
{
    // Convert raw_data (char*) to uint16_t* for encryption
    std::vector<uint8_t> raw_data_bytes(reinterpret_cast<const uint8_t*>(raw_data), reinterpret_cast<const uint8_t*>(raw_data) + raw_data_size);
    auto uint16_data = toUint16Array(raw_data_bytes.data(), raw_data_bytes.size());

    // Perform encryption
    auto result = EncryptECB(uint16_data.data(), uint16_data.size(), EncryptionKey);

    // Convert the result back to char*
    auto result_bytes = toUint8Array(result.data(), result.size());
    packed_data = new char[result_bytes.size()];
    std::memcpy(packed_data, result_bytes.data(), result_bytes.size());
    packed_size = result_bytes.size();
}

void PacketBuilder::Encryption::CAES::UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size)
{
    // Convert packed_data (char*) to uint16_t* for decryption
    std::vector<uint8_t> packed_data_bytes(reinterpret_cast<const uint8_t*>(packed_data), reinterpret_cast<const uint8_t*>(packed_data) + size);
    auto uint16_data = toUint16Array(packed_data_bytes.data(), packed_data_bytes.size());

    // Perform decryption
    auto result = DecryptECB(uint16_data.data(), uint16_data.size(), EncryptionKey);

    // Convert the result back to char*
    auto result_bytes = toUint8Array(result.data(), result.size());
    unpacked_data = new char[result_bytes.size()];
    std::memcpy(unpacked_data, result_bytes.data(), result_bytes.size());
    unpacked_size = result_bytes.size();
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::toUint16Array(const uint8_t *input, size_t length) {
    std::vector<uint16_t> output((length + 1) / 2, 0); // +1 for padding in case of odd length
    for (size_t i = 0; i < length; ++i) {
        size_t index = i / 2;
        if (i % 2 == 0) {
            output[index] = input[i];
        } else {
            output[index] |= (input[i] << 8);
        }
    }
    return output;
}

std::vector<uint8_t> PacketBuilder::Encryption::CAES::toUint8Array(const uint16_t *input, size_t length) {
    std::vector<uint8_t> output(length * 2);
    for (size_t i = 0; i < length; ++i) {
        output[2 * i] = input[i] & 0xFF;
        output[2 * i + 1] = (input[i] >> 8) & 0xFF;
    }
    return output;
}

uint16_t *PacketBuilder::Encryption::CAES::VectorToArray(const std::vector<unsigned char> &vec) {
    size_t size = vec.size();
    uint16_t* arr = new uint16_t[(size + 1) / 2];
    std::memset(arr, 0, (size + 1) / 2 * sizeof(uint16_t)); // Zero initialize the array
    for (size_t i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            arr[i / 2] = vec[i];
        } else {
            arr[i / 2] |= (vec[i] << 8);
        }
    }
    return arr;
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::ArrayToVector(const uint16_t *arr, size_t size) {
    std::vector<unsigned char> vec(size * 2);
    for (size_t i = 0; i < size; ++i) {
        vec[2 * i] = arr[i] & 0xFF;
        vec[2 * i + 1] = (arr[i] >> 8) & 0xFF;
    }
    return vec;
}

void PacketBuilder::Encryption::CAES::Init()
{
    switch (AESKeyLength)
    {
    case EAESKeyLength::AES_128:
    {
        Nk = 4;
        Nr = 10;
        break;
    }
    case EAESKeyLength::AES_192:
    {
        Nk = 6;
        Nr = 12;
        break;
    }
    case EAESKeyLength::AES_256:
    {
        Nk = 8;
        Nr = 14;
        break;
    }
    }
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::EncryptECB(const uint16_t* in, size_t inLen, const unsigned char key[]) {
    std::vector<uint8_t> inputBytes = toUint8Array(in, inLen);
    size_t byteLen = inputBytes.size();
    size_t paddedLen = byteLen + (blockBytesLen - byteLen % blockBytesLen);
    inputBytes.resize(paddedLen, paddedLen - byteLen);

    std::vector<uint8_t> outputBytes(paddedLen);
    unsigned char* roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
    KeyExpansion(key, roundKeys);
    for (size_t i = 0; i < paddedLen; i += blockBytesLen) {
        EncryptBlock(inputBytes.data() + i, outputBytes.data() + i, roundKeys);
    }

    delete[] roundKeys;
    return toUint16Array(outputBytes.data(), paddedLen);
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::DecryptECB(const uint16_t* in, size_t inLen, const unsigned char key[]) {
    std::vector<uint8_t> inputBytes = toUint8Array(in, inLen);
    size_t byteLen = inputBytes.size();

    std::vector<uint8_t> outputBytes(byteLen);
    unsigned char* roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
    KeyExpansion(key, roundKeys);
    for (size_t i = 0; i < byteLen; i += blockBytesLen) {
        DecryptBlock(inputBytes.data() + i, outputBytes.data() + i, roundKeys);
    }

    unsigned int padding = outputBytes[byteLen - 1];
    if (padding < 1 || padding > blockBytesLen) {
        padding = 0;
    }

    size_t dataLen = byteLen - padding;
    outputBytes.resize(dataLen);

    delete[] roundKeys;
    return toUint16Array(outputBytes.data(), dataLen);
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::EncryptCBC(const uint16_t* in, size_t inLen, const unsigned char key[], const unsigned char* iv) {
    std::vector<uint8_t> inputBytes = toUint8Array(in, inLen);
    size_t byteLen = inputBytes.size();
    size_t paddedLen = byteLen + (blockBytesLen - byteLen % blockBytesLen);
    inputBytes.resize(paddedLen, paddedLen - byteLen);

    std::vector<uint8_t> outputBytes(paddedLen);
    unsigned char* roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
    unsigned char block[blockBytesLen];
    unsigned char currentIv[blockBytesLen];
    std::memcpy(currentIv, iv, blockBytesLen);
    KeyExpansion(key, roundKeys);

    for (size_t i = 0; i < paddedLen; i += blockBytesLen) {
        XorBlocks(currentIv, inputBytes.data() + i, block, blockBytesLen);
        EncryptBlock(block, outputBytes.data() + i, roundKeys);
        std::memcpy(currentIv, outputBytes.data() + i, blockBytesLen);
    }

    delete[] roundKeys;
    return toUint16Array(outputBytes.data(), paddedLen);
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::DecryptCBC(const uint16_t* in, size_t inLen, const unsigned char key[], const unsigned char* iv) {
    std::vector<uint8_t> inputBytes = toUint8Array(in, inLen);
    size_t byteLen = inputBytes.size();

    std::vector<uint8_t> outputBytes(byteLen);
    unsigned char* roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
    unsigned char block[blockBytesLen];
    unsigned char currentIv[blockBytesLen];
    std::memcpy(currentIv, iv, blockBytesLen);
    KeyExpansion(key, roundKeys);

    for (size_t i = 0; i < byteLen; i += blockBytesLen) {
        DecryptBlock(inputBytes.data() + i, block, roundKeys);
        XorBlocks(currentIv, block, outputBytes.data() + i, blockBytesLen);
        std::memcpy(currentIv, inputBytes.data() + i, blockBytesLen);
    }

    unsigned int padding = outputBytes[byteLen - 1];
    if (padding < 1 || padding > blockBytesLen) {
        padding = 0;
    }

    size_t dataLen = byteLen - padding;
    outputBytes.resize(dataLen);

    delete[] roundKeys;
    return toUint16Array(outputBytes.data(), dataLen);
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::EncryptCFB(const uint16_t* in, size_t inLen, const unsigned char key[], const unsigned char* iv) {
    std::vector<uint8_t> inputBytes = toUint8Array(in, inLen);
    size_t byteLen = inputBytes.size();

    std::vector<uint8_t> outputBytes(byteLen);
    unsigned char* roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
    unsigned char block[blockBytesLen];
    unsigned char currentIv[blockBytesLen];
    std::memcpy(currentIv, iv, blockBytesLen);
    KeyExpansion(key, roundKeys);

    for (size_t i = 0; i < byteLen; i += blockBytesLen) {
        EncryptBlock(currentIv, block, roundKeys);
        size_t blockSize = (byteLen - i >= blockBytesLen) ? blockBytesLen : (byteLen - i);
        XorBlocks(inputBytes.data() + i, block, outputBytes.data() + i, blockSize);
        std::memcpy(currentIv, outputBytes.data() + i, blockBytesLen);
    }

    delete[] roundKeys;
    return toUint16Array(outputBytes.data(), byteLen);
}

std::vector<uint16_t> PacketBuilder::Encryption::CAES::DecryptCFB(const uint16_t* in, size_t inLen, const unsigned char key[], const unsigned char* iv) {
    std::vector<uint8_t> inputBytes = toUint8Array(in, inLen);
    size_t byteLen = inputBytes.size();

    std::vector<uint8_t> outputBytes(byteLen);
    unsigned char* roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
    unsigned char block[blockBytesLen];
    unsigned char currentIv[blockBytesLen];
    std::memcpy(currentIv, iv, blockBytesLen);
    KeyExpansion(key, roundKeys);

    for (size_t i = 0; i < byteLen; i += blockBytesLen) {
        EncryptBlock(currentIv, block, roundKeys);
        size_t blockSize = (byteLen - i >= blockBytesLen) ? blockBytesLen : (byteLen - i);
        XorBlocks(inputBytes.data() + i, block, outputBytes.data() + i, blockSize);
        std::memcpy(currentIv, inputBytes.data() + i, blockBytesLen);
    }

    delete[] roundKeys;
    return toUint16Array(outputBytes.data(), byteLen);
}



void PacketBuilder::Encryption::CAES::CheckLength(unsigned int len) {
    if (len == 0) {
        throw std::length_error("Plaintext length must be greater than 0");
    }
}

void PacketBuilder::Encryption::CAES::EncryptBlock(const unsigned char in[], unsigned char out[],
                       unsigned char *roundKeys) {
    unsigned char state[4][Nb];
    unsigned int i, j, round;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            state[i][j] = in[i + 4 * j];
        }
    }

    AddRoundKey(state, roundKeys);

    for (round = 1; round <= Nr - 1; round++) {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys + round * 4 * Nb);
    }

    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, roundKeys + Nr * 4 * Nb);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            out[i + 4 * j] = state[i][j];
        }
    }
}

void PacketBuilder::Encryption::CAES::DecryptBlock(const unsigned char in[], unsigned char out[],
                       unsigned char *roundKeys) {
    unsigned char state[4][Nb];
    unsigned int i, j, round;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            state[i][j] = in[i + 4 * j];
        }
    }

    AddRoundKey(state, roundKeys + Nr * 4 * Nb);

    for (round = Nr - 1; round >= 1; round--) {
        InvSubBytes(state);
        InvShiftRows(state);
        AddRoundKey(state, roundKeys + round * 4 * Nb);
        InvMixColumns(state);
    }

    InvSubBytes(state);
    InvShiftRows(state);
    AddRoundKey(state, roundKeys);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            out[i + 4 * j] = state[i][j];
        }
    }
}

void PacketBuilder::Encryption::CAES::SubBytes(unsigned char state[4][Nb]) {
    unsigned int i, j;
    unsigned char t;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            t = state[i][j];
            state[i][j] = sbox[t / 16][t % 16];
        }
    }
}

void PacketBuilder::Encryption::CAES::ShiftRow(unsigned char state[4][Nb], unsigned int i,
                   unsigned int n)  // shift row i on n positions
{
    unsigned char tmp[Nb];
    for (unsigned int j = 0; j < Nb; j++) {
        tmp[j] = state[i][(j + n) % Nb];
    }
    memcpy(state[i], tmp, Nb * sizeof(unsigned char));
}

void PacketBuilder::Encryption::CAES::ShiftRows(unsigned char state[4][Nb]) {
    ShiftRow(state, 1, 1);
    ShiftRow(state, 2, 2);
    ShiftRow(state, 3, 3);
}

unsigned char PacketBuilder::Encryption::CAES::xtime(unsigned char b)  // multiply on x
{
    return (b << 1) ^ (((b >> 7) & 1) * 0x1b);
}

void PacketBuilder::Encryption::CAES::MixColumns(unsigned char state[4][Nb]) {
    unsigned char temp_state[4][Nb];

    for (size_t i = 0; i < 4; ++i) {
        memset(temp_state[i], 0, 4);
    }

    for (size_t i = 0; i < 4; ++i) {
        for (size_t k = 0; k < 4; ++k) {
            for (size_t j = 0; j < 4; ++j) {
                if (CMDS[i][k] == 1)
                    temp_state[i][j] ^= state[k][j];
                else
                    temp_state[i][j] ^= GF_MUL_TABLE[CMDS[i][k]][state[k][j]];
            }
        }
    }

    for (size_t i = 0; i < 4; ++i) {
        memcpy(state[i], temp_state[i], 4);
    }
}

void PacketBuilder::Encryption::CAES::AddRoundKey(unsigned char state[4][Nb], unsigned char *key) {
    unsigned int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            state[i][j] = state[i][j] ^ key[i + 4 * j];
        }
    }
}

void PacketBuilder::Encryption::CAES::SubWord(unsigned char *a) {
    int i;
    for (i = 0; i < 4; i++) {
        a[i] = sbox[a[i] / 16][a[i] % 16];
    }
}

void PacketBuilder::Encryption::CAES::RotWord(unsigned char *a) {
    unsigned char c = a[0];
    a[0] = a[1];
    a[1] = a[2];
    a[2] = a[3];
    a[3] = c;
}

void PacketBuilder::Encryption::CAES::XorWords(unsigned char *a, unsigned char *b, unsigned char *c) {
    int i;
    for (i = 0; i < 4; i++) {
        c[i] = a[i] ^ b[i];
    }
}

void PacketBuilder::Encryption::CAES::Rcon(unsigned char *a, unsigned int n) {
    unsigned int i;
    unsigned char c = 1;
    for (i = 0; i < n - 1; i++) {
        c = xtime(c);
    }

    a[0] = c;
    a[1] = a[2] = a[3] = 0;
}

void PacketBuilder::Encryption::CAES::KeyExpansion(const unsigned char key[], unsigned char w[]) {
    unsigned char temp[4];
    unsigned char rcon[4];

    unsigned int i = 0;
    while (i < 4 * Nk) {
        w[i] = key[i];
        i++;
    }

    i = 4 * Nk;
    while (i < 4 * Nb * (Nr + 1)) {
        temp[0] = w[i - 4 + 0];
        temp[1] = w[i - 4 + 1];
        temp[2] = w[i - 4 + 2];
        temp[3] = w[i - 4 + 3];

        if (i / 4 % Nk == 0) {
            RotWord(temp);
            SubWord(temp);
            Rcon(rcon, i / (Nk * 4));
            XorWords(temp, rcon, temp);
        } else if (Nk > 6 && i / 4 % Nk == 4) {
            SubWord(temp);
        }

        w[i + 0] = w[i - 4 * Nk] ^ temp[0];
        w[i + 1] = w[i + 1 - 4 * Nk] ^ temp[1];
        w[i + 2] = w[i + 2 - 4 * Nk] ^ temp[2];
        w[i + 3] = w[i + 3 - 4 * Nk] ^ temp[3];
        i += 4;
    }
}

void PacketBuilder::Encryption::CAES::InvSubBytes(unsigned char state[4][Nb]) {
    unsigned int i, j;
    unsigned char t;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < Nb; j++) {
            t = state[i][j];
            state[i][j] = inv_sbox[t / 16][t % 16];
        }
    }
}

void PacketBuilder::Encryption::CAES::InvMixColumns(unsigned char state[4][Nb]) {
    unsigned char temp_state[4][Nb];

    for (size_t i = 0; i < 4; ++i) {
        memset(temp_state[i], 0, 4);
    }

    for (size_t i = 0; i < 4; ++i) {
        for (size_t k = 0; k < 4; ++k) {
            for (size_t j = 0; j < 4; ++j) {
                temp_state[i][j] ^= GF_MUL_TABLE[INV_CMDS[i][k]][state[k][j]];
            }
        }
    }

    for (size_t i = 0; i < 4; ++i) {
        memcpy(state[i], temp_state[i], 4);
    }
}

void PacketBuilder::Encryption::CAES::InvShiftRows(unsigned char state[4][Nb]) {
    ShiftRow(state, 1, Nb - 1);
    ShiftRow(state, 2, Nb - 2);
    ShiftRow(state, 3, Nb - 3);
}

void PacketBuilder::Encryption::CAES::XorBlocks(const unsigned char *a, const unsigned char *b,
                    unsigned char *c, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        c[i] = a[i] ^ b[i];
    }
}

void PacketBuilder::Encryption::CAES::printHexArray(unsigned char a[], unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        printf("%02x ", a[i]);
    }
}

void PacketBuilder::Encryption::CAES::printHexVector(std::vector<unsigned char> a) {
    for (unsigned int i = 0; i < a.size(); i++) {
        printf("%02x ", a[i]);
    }
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::EncryptECB(std::vector<unsigned char> in,
                                                                       std::vector<unsigned char> key) {
    std::vector<uint16_t> out = EncryptECB(VectorToArray(in), in.size(), key.data());
    std::vector<unsigned char> v = ArrayToVector(out.data(), (in.size() + 1) / 2);
    return v;
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::DecryptECB(std::vector<unsigned char> in,
                                                                       std::vector<unsigned char> key) {
    std::vector<uint16_t> out = DecryptECB(VectorToArray(in), in.size(), key.data());
    std::vector<unsigned char> v = ArrayToVector(out.data(), (in.size() + 1) / 2);
    return v;
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::EncryptCBC(std::vector<unsigned char> in,
                                                                       std::vector<unsigned char> key,
                                                                       std::vector<unsigned char> iv) {
    std::vector<uint16_t> out = EncryptCBC(VectorToArray(in), in.size(), key.data(), iv.data());
    std::vector<unsigned char> v = ArrayToVector(out.data(), (in.size() + 1) / 2);
    return v;
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::DecryptCBC(std::vector<unsigned char> in,
                                                                       std::vector<unsigned char> key,
                                                                       std::vector<unsigned char> iv) {
    std::vector<uint16_t> out = DecryptCBC(VectorToArray(in), in.size(), key.data(), iv.data());
    std::vector<unsigned char> v = ArrayToVector(out.data(), (in.size() + 1) / 2);
    return v;
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::EncryptCFB(std::vector<unsigned char> in,
                                                                       std::vector<unsigned char> key,
                                                                       std::vector<unsigned char> iv) {
    std::vector<uint16_t> out = EncryptCFB(VectorToArray(in), in.size(), key.data(), iv.data());
    std::vector<unsigned char> v = ArrayToVector(out.data(), (in.size() + 1) / 2);
    return v;
}

std::vector<unsigned char> PacketBuilder::Encryption::CAES::DecryptCFB(std::vector<unsigned char> in,
                                                                       std::vector<unsigned char> key,
                                                                       std::vector<unsigned char> iv) {
    std::vector<uint16_t> out = DecryptCFB(VectorToArray(in), in.size(), key.data(), iv.data());
    std::vector<unsigned char> v = ArrayToVector(out.data(), (in.size() + 1) / 2);
    return v;
}

