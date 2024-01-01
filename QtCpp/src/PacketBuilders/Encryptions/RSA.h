#ifndef CRSA_H
#define CRSA_H
#include <PacketBuilders/PacketBuilder.h>

#include <iostream>
#include <cmath>
#include <cstdlib>

namespace PacketBuilder{
namespace Encryption{
class CRSA:public IPacketBuilder
{
public:
    CRSA(int public_key = 5, int private_key = 173, int n = 323);
    void GenerateKeys(int &public_key, int &private_key, int &n);
    bool ValidateKeys(int public_key, int private_key);

    // IPacketBuilder interface
public:
    void PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size) override;
    void UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size) override;
    EBodyType GetType() override{return EBodyType::EncRsa;}

private:
    bool IsPrime(int num);
    int GCD(int a, int b);
    int GenerateRandomPrime();
    uint16_t Encrypt(unsigned char message, int public_key, int n);
    char Decrypt(uint16_t encryptedMessage, int private_key, int n);

private:
    int PublicKey = -1;
    int PrivateKey = -1;
    int N = -1;
};
}
}
#endif


