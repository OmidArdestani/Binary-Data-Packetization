#include "RSA.h"
#include <cassert>

using namespace std;

///
/// \brief CRSA
/// \param public_key  : Should be prime
/// \param private_key : Should be prime and not equal the public_key
///
PacketBuilder::Encryption::CRSA::CRSA(int public_key, int private_key, int n):
    IPacketBuilder(),
    PublicKey(public_key),
    PrivateKey(private_key),
    N(n)
{
    // validation
    assert(ValidateKeys(PublicKey,PrivateKey));
    assert(PublicKey != PrivateKey);
}


void PacketBuilder::Encryption::CRSA::PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size)
{
    auto packed_data_temp = static_cast<char*>(std::malloc(raw_data_size * 2));
    auto int_packed_data = reinterpret_cast<uint16_t*>(packed_data_temp);

    for(int i = 0; i < raw_data_size; ++i)
    {
        int_packed_data[i] = 0;
        auto ev = Encrypt(raw_data[i], PublicKey, N);
        int_packed_data[i] = ev;
    }

    packed_size = raw_data_size * 2;
    packed_data = packed_data_temp;
}

void PacketBuilder::Encryption::CRSA::UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size)
{
    auto unpacked_data_temp = static_cast<char*>(std::malloc(size / 2));
    auto int_packed_data = reinterpret_cast<const uint16_t*>(packed_data);
    int int_packed_data_size = size / 2;

    for(int i = 0; i < int_packed_data_size; ++i)
    {
        unpacked_data_temp[i] = 0;
        auto dv = Decrypt(int_packed_data[i], PrivateKey, N);
        unpacked_data_temp[i] = dv;
    }

    unpacked_size = size / 2;
    unpacked_data = unpacked_data_temp;
}

// Function to calculate GCD of two numbers
int PacketBuilder::Encryption::CRSA::GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

// Function to generate a random prime number
int PacketBuilder::Encryption::CRSA::GenerateRandomPrime() {
    int num;
    do {
        num = rand() % 100 + 50; // Adjust the range as needed
    } while (num % 2 == 0);     // Ensure it's odd
    return num;
}

// Function to check if a number is prime
bool PacketBuilder::Encryption::CRSA::IsPrime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to generate public and private keys
void PacketBuilder::Encryption::CRSA::GenerateKeys(int &public_key, int &private_key, int &n)
{
    int p, q;

    // Choose two random prime numbers
    do {
        p = GenerateRandomPrime();
    } while (!IsPrime(p));

    do {
        q = GenerateRandomPrime();
    } while (!IsPrime(q) || p == q);

    n = p * q; // Calculate n
    int phi = (p - 1) * (q - 1); // Calculate Euler's totient function

    // Choose public key e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        public_key = rand() % (phi - 2) + 2;
    } while (GCD(public_key, phi) != 1);

    // Calculate private key d such that (d * e) % phi = 1
    private_key = 1;
    while (((private_key * public_key) % phi) != 1) {
        ++private_key;
    }
}

// Function to validate public and private keys
bool PacketBuilder::Encryption::CRSA::ValidateKeys(int public_key, int private_key)
{
    int p = 17;
    int q = 19;
    int phi = (p - 1) * (q - 1);
    return (public_key > 1 && public_key < phi && GCD(public_key, phi) == 1 && (private_key * public_key) % phi == 1);
}

#include <iostream>

// Function to calculate (base^exponent) % modulus
long long mod_exp(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;  // Ensure base is within the modulus range

    while (exponent > 0) {
        // If exponent is odd, multiply result with base
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        // Exponent must be even now
        exponent = exponent / 2;
        base = (base * base) % modulus;
    }

    return result;
}

// Function to Encrypt a message
uint16_t PacketBuilder::Encryption::CRSA::Encrypt(unsigned char message, int public_key, int n)
{
    uint64_t result = mod_exp(message,public_key,n);
    return static_cast<uint16_t>(result);
}

// Function to Decrypt a message
char PacketBuilder::Encryption::CRSA::Decrypt(uint16_t encrypted_message, int private_key, int n)
{
    uint64_t result = mod_exp(encrypted_message,private_key,n);
    return static_cast<char>(result);
}
