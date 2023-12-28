#ifndef IPACKETBUILDER_H
#define IPACKETBUILDER_H
class IPacketBuilder
{
public:
    virtual void PackData(const char* raw_data, int raw_data_size, char* packed_data, int& packed_size) = 0;
    virtual void UnpackData(const char* packed_data, int size, char* unpacked_data, int& unpacked_size) = 0;
};
#endif
