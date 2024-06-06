#include "CRC16.h"

#include <cstring>

HeaderBuilder::ValidationHeader::CCRC16::CCRC16():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC16::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto crc_value = CalculateCRC16(body_data, size);
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

bool HeaderBuilder::ValidationHeader::CCRC16::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto packet_crc_value = *reinterpret_cast<const unsigned short*>(packet_data);
        int crc_size = sizeof(packet_crc_value);
        auto crc_value = CalculateCRC16(packet_data + crc_size, size - crc_size);

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

unsigned short HeaderBuilder::ValidationHeader::CCRC16::CalculateCRC16(const char* data, int length)
{
    const unsigned short polynomial = 0x8005; // CRC-16 polynomial

    unsigned short crc = 0;

    for (int i = 0; i < length; i++)
    {
        crc ^= static_cast<unsigned short>(data[i]) << 8;

        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x8000)
                crc = (crc << 1) ^ polynomial;
            else
                crc <<= 1;
        }
    }

    return crc;
}
