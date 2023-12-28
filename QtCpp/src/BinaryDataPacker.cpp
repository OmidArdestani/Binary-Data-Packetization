#include "BinaryDataPacker.h"

void CBinaryDataPacker::AddPacketBuilder(IPacketBuilder *packet_builder)
{
    PacketBuilders.push_back(packet_builder);
}

void CBinaryDataPacker::AddSOFBuilder(IHeaderBuilder *header_builder)
{
    SOFs.push_back(header_builder);
}

void CBinaryDataPacker::AddEOFBuilder(IHeaderBuilder *header_builder)
{
    EOFs.push_back(header_builder);
}

void CBinaryDataPacker::GetPacket(const char *raw_data, int size, char *result_buffer, int &result_size)
{
    // build body
    for(auto builder = PacketBuilders.cbegin(); builder != PacketBuilders.cend(); ++builder)
    {
        (*builder)->PackData(raw_data, size, result_buffer, result_size);
    }

    // builde header
    for(auto builder = SOFs.cbegin(); builder != SOFs.cend(); ++builder)
    {
        (*builder)->BuildHeader(raw_data, size, result_buffer, result_size);
    }

    // build footer
    for(auto builder = EOFs.cbegin(); builder != EOFs.cend(); ++builder)
    {
        (*builder)->BuildHeader(raw_data, size, result_buffer, result_size);
    }
}

void CBinaryDataPacker::UnpackData(const char *packed_data, int packet_size, char *result_buffer, int &result_size)
{
    // build footer
    for(auto builder = EOFs.cbegin(); builder != EOFs.cend(); ++builder)
    {
        (*builder)->CheckHeader(packed_data, packet_size/*, result_buffer, result_size*/);
    }

    // builde header
    for(auto builder = SOFs.cbegin(); builder != SOFs.cend(); ++builder)
    {
        (*builder)->CheckHeader(packed_data, packet_size/*, result_buffer, result_size*/);
    }

    // build body
    for(auto builder = PacketBuilders.cbegin(); builder != PacketBuilders.cend(); ++builder)
    {
        (*builder)->PackData(packed_data, packet_size, result_buffer, result_size);
    }
}
