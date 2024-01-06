#include "Checksum.h"

HeaderBuilder::ValidationHeader::CChecksum::CChecksum():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CChecksum::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto crc_value = CalculateChecksum(body_data, size);
        int crc_size = sizeof(crc_value);

        char* result_buffer_temp = static_cast<char*>(std::malloc(size + crc_size));

        std::memcpy(result_buffer_temp, &crc_value, crc_size);
        std::memcpy(result_buffer_temp + crc_size, body_data, size);

        result_buffer = result_buffer_temp;
        result_size = size + crc_size;
    }
    else
    {

    }
}

bool HeaderBuilder::ValidationHeader::CChecksum::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        unsigned char packet_crc_value = packet_data[0];
        int crc_size = sizeof(packet_crc_value);
        auto crc_value = CalculateChecksum(packet_data + crc_size, size - crc_size);

        if(crc_value == packet_crc_value)
        {
            char* result_buffer_temp = static_cast<char*>(std::malloc(size - crc_size));

            std::memcpy(result_buffer_temp, packet_data + crc_size, size - crc_size);

            result_buffer = result_buffer_temp;
            result_size = size - crc_size;
            return true;
        }
    }
    else
    {

    }
    return false;
}

unsigned char HeaderBuilder::ValidationHeader::CChecksum::CalculateChecksum(const char* data, int length)
{
    unsigned char checksum = 0;

    for (int i = 0; i < length; i++)
        checksum += data[i];

    return checksum;
}
