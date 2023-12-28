#include "DEFLATE.h"

PacketBuilder::Compressor::CDEFLATE::CDEFLATE():IPacketBuilder()
{

}


void PacketBuilder::Compressor::CDEFLATE::PackData(const char *raw_data, int raw_data_size, char *packed_data, int &packed_size)
{
}

void PacketBuilder::Compressor::CDEFLATE::UnpackData(const char *packed_data, int size, char *unpacked_data, int &unpacked_size)
{
}
