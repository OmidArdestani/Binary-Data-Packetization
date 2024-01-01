#ifndef CTWOFISH_H
#define CTWOFISH_H
#include <PacketBuilders/PacketBuilder.h>

namespace PacketBuilder{
namespace Encryption{
class CTwoFish:public IPacketBuilder
{
public:
    CTwoFish();

    // IPacketBuilder interface
public:
    void PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size) override;
    void UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size) override;
    EBodyType GetType() override{return EBodyType::EncTwoFish;}
};
}
}
#endif
