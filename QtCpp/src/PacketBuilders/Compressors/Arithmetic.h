#ifndef CARITHMETIC_H
#define CARITHMETIC_H
#include <PacketBuilders/PacketBuilder.h>

namespace PacketBuilder{
namespace Compressor{
class CArithmetic:public IPacketBuilder
{
public:
    CArithmetic();

    // IPacketBuilder interface
public:
    void PackData(const char *raw_data, int raw_data_size, char *&packed_data, int &packed_size) override;
    void UnpackData(const char *packed_data, int size, char *&unpacked_data, int &unpacked_size) override;
};
}
}
#endif
