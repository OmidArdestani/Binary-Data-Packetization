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


void PacketBuilder::Encryption::CRSA::PackData(const char *raw_data, int raw_data_size, char *packed_data, int &packed_size)
{
    packed_data = static_cast<char*>(std::malloc(raw_data_size));
    packed_size = raw_data_size;

    for(int i = 0; i < raw_data_size; i += sizeof(int))
    {
        packed_data[i] = Encrypt((int)(raw_data[i]), PublicKey, N);
    }
}

void PacketBuilder::Encryption::CRSA::UnpackData(const char *packed_data, int size, char *unpacked_data, int &unpacked_size)
{
    unpacked_data = static_cast<char*>(std::malloc(size));
    unpacked_size = size;

    for(int i = 0; i < size; i += sizeof(int))
    {
        unpacked_data[i] = Decrypt((int)(packed_data[i]), PrivateKey, N);
    }
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

// Function to Encrypt a message
int PacketBuilder::Encryption::CRSA::Encrypt(int message, int public_key, int n) {
    return static_cast<int>(pow(message, public_key)) % n;
}

// Function to Decrypt a message
int PacketBuilder::Encryption::CRSA::Decrypt(int encryptedMessage, int private_key, int n) {
    return static_cast<int>(pow(encryptedMessage, private_key)) % n;
}
