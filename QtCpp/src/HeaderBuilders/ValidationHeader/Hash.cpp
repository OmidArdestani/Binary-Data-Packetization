#include "Hash.h"

#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <array>

HeaderBuilder::ValidationHeader::CHashSHA256::CHashSHA256():IHeaderBuilder()
{

}

// Define the SHA-256 constants
constexpr uint32_t K[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Utility functions
inline uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t sigma0(uint32_t x) {
    return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

inline uint32_t sigma1(uint32_t x) {
    return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

inline uint32_t gamma0(uint32_t x) {
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

inline uint32_t gamma1(uint32_t x) {
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

void HeaderBuilder::ValidationHeader::CHashSHA256::CalcSha256(const char* input, int size, char*& result, int& result_size)
{
    // Initial hash values
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Process the input in 512-bit chunks
    for (size_t i = 0; i < size; i += 64)
    {
        std::array<uint32_t, 64> w = {0};

        // Copy the chunk into the message schedule
        for (size_t j = 0; j < 16; ++j)
        {
            w[j] = (static_cast<uint32_t>(input[i + j * 4]) << 24) |
                   (static_cast<uint32_t>(input[i + j * 4 + 1]) << 16) |
                   (static_cast<uint32_t>(input[i + j * 4 + 2]) << 8) |
                   static_cast<uint32_t>(input[i + j * 4 + 3]);
        }

        // Extend the message schedule
        for (size_t j = 16; j < 64; ++j)
            w[j] = gamma1(w[j - 2]) + w[j - 7] + gamma0(w[j - 15]) + w[j - 16];

        // Initialize working variables
        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t h_ = h[7];

        // Main loop
        for (size_t j = 0; j < 64; ++j)
        {
            uint32_t t1 = h_ + sigma1(e) + ch(e, f, g) + K[j] + w[j];
            uint32_t t2 = sigma0(a) + maj(a, b, c);

            h_ = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update the hash values
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_;
    }

    // Combine the hash values into the final hash
    std::ostringstream sha_result;
    for (uint32_t value : h)
    {
        sha_result << std::hex << std::setw(8) << std::setfill('0') << value;
    }

    result_size = (int)sha_result.str().length();
    result = static_cast<char*>(std::malloc(result_size));

    std::memcpy(result, sha_result.str().c_str(), result_size);
}


void HeaderBuilder::ValidationHeader::CHashSHA256::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    char* hash_result = nullptr;
    int hash_size = 0;

    CalcSha256(body_data, size, hash_result, hash_size);

    char* result_buffer_temp = static_cast<char*>(std::malloc(size + hash_size));
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        std::memcpy(result_buffer_temp, hash_result, hash_size);
        std::memcpy(result_buffer_temp + hash_size, body_data, size);
    }
    else
    {
        std::memcpy(result_buffer_temp, body_data, size);
        std::memcpy(result_buffer_temp + size, hash_result, hash_size);
    }
    result_buffer = result_buffer_temp;
    result_size = size + hash_size;
}

bool HeaderBuilder::ValidationHeader::CHashSHA256::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        int hash_size = HashSize;
        char* hash_result = nullptr;
        CalcSha256(packet_data + hash_size, size - hash_size, hash_result, hash_size);

        auto r = std::memcmp((const char*)hash_result, (const char*)packet_data, size_t(hash_size));
        if(!r)
        {
            char* result_buffer_temp = static_cast<char*>(std::malloc(size - hash_size));

            std::memcpy(result_buffer_temp, packet_data + hash_size, size - hash_size);

            result_buffer = result_buffer_temp;
            result_size = size - hash_size;
            return true;
        }
    }
    else
    {

    }
    return false;
}


