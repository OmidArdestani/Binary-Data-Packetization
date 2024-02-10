#include "BinaryDataPacker.h"

void CBinaryDataPacketizer::AddPacketBuilder(IPacketBuilder *packet_builder)
{
    PacketBuilders.push_back(packet_builder);

    AdditionalInfo.AddBodyType(packet_builder->GetType());
}

void CBinaryDataPacketizer::SetSOFBuilder(IHeaderBuilder *header_builder)
{
    SOFHeaderBuilder = header_builder;

    AdditionalInfo.SOFHeaderType = static_cast<uint8_t>(SOFHeaderBuilder->GetType());
}

void CBinaryDataPacketizer::SetEOFBuilder(IHeaderBuilder *header_builder)
{
    header_builder->SetHeaderPosition(IHeaderBuilder::EHeaderPostion::EndOfFrame);
    EOFHeaderBuilder = header_builder;

    AdditionalInfo.EOFHeaderType = static_cast<uint8_t>(EOFHeaderBuilder->GetType());
}

void CBinaryDataPacketizer::InsertAdditionalInfo(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    if(!body_data) return;
    if(size < 1) return;

    AdditionalInfo.BodySize = size;

    int additional_info_size = sizeof(AdditionalInfo);
    auto result_size_temp = size + additional_info_size;
    auto result_buffer_temp = static_cast<char*>(std::malloc(result_size_temp));
    // auto additional_data = reinterpret_cast<char*>();

    std::memcpy(result_buffer_temp, &AdditionalInfo, additional_info_size);
    std::memcpy(result_buffer_temp + additional_info_size, body_data, size);

    result_buffer = result_buffer_temp;
    result_size = result_size_temp;
}

void CBinaryDataPacketizer::ExtractAdditionalInfo(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    int result_size_temp = size - sizeof(AdditionalInfo);
    auto result_buffer_temp = static_cast<char*>(std::malloc(result_size_temp));

    std::memcpy(&AdditionalInfo, body_data, sizeof(AdditionalInfo));
    std::memcpy(result_buffer_temp, body_data + sizeof(AdditionalInfo), result_size_temp);

    result_size = result_size_temp;
    result_buffer = result_buffer_temp;
}

void CBinaryDataPacketizer::GetPacket(const char *raw_data, int size, char *&result_buffer, int &result_size)
{
    if(!raw_data) return;
    if(size < 1) return;

    // build body
    for(auto builder = PacketBuilders.cbegin(); builder != PacketBuilders.cend(); ++builder)
    {
        (*builder)->PackData(raw_data, size, result_buffer, result_size);
    }
    if(!result_buffer) return;
    if(result_size < 1) return;

    // insert additional info
    InsertAdditionalInfo(result_buffer, result_size, result_buffer, result_size);

    // builde header
    if(SOFHeaderBuilder)
        SOFHeaderBuilder->BuildHeader(result_buffer, result_size, result_buffer, result_size);

    // build footer
    if(EOFHeaderBuilder)
        EOFHeaderBuilder->BuildHeader(result_buffer, result_size, result_buffer, result_size);

    if(result_size > MAX_PACKET_SIZE)
        throw std::runtime_error("Packet is bigger than capability!");
}

void CBinaryDataPacketizer::UnpackData(const char *packed_data, int packet_size, char *&result_buffer, int &result_size)
{
    // remove header
    if(SOFHeaderBuilder)
    {
        if(!SOFHeaderBuilder->CheckHeader(packed_data, packet_size, result_buffer, result_size))
            return; // the header is not correct
    }

    // remove footer
    if(EOFHeaderBuilder)
    {
        if(!EOFHeaderBuilder->CheckHeader(packed_data, packet_size, result_buffer, result_size))
            return; // the footer is not correct
    }

    ExtractAdditionalInfo(result_buffer, result_size, result_buffer, result_size);

    // unpack body
    for(auto builder = PacketBuilders.cbegin(); builder != PacketBuilders.cend(); ++builder)
    {
        (*builder)->UnpackData(result_buffer, result_size, result_buffer, result_size);
    }
}
