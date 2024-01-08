#include "CRC8.h"

HeaderBuilder::ValidationHeader::CCRC8::CCRC8():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC8::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    auto crc_value = CalculateCRC8(body_data, size);
    int crc_size = sizeof(crc_value);

    char* result_buffer_temp = static_cast<char*>(std::malloc(size + crc_size));

    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        std::memcpy(result_buffer_temp, &crc_value, crc_size);
        std::memcpy(result_buffer_temp + crc_size, body_data, size);
    }
    else
    {
        std::memcpy(result_buffer_temp, body_data, size);
        std::memcpy(result_buffer_temp + size, &crc_value, crc_size);
    }
    result_buffer = result_buffer_temp;
    result_size = size + crc_size;
}

bool HeaderBuilder::ValidationHeader::CCRC8::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        unsigned char packet_crc_value = packet_data[0];
        int crc_size = sizeof(packet_crc_value);
        auto crc_value = CalculateCRC8(packet_data + crc_size, size - crc_size);

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


unsigned char HeaderBuilder::ValidationHeader::CCRC8::CalculateCRC8(const char* data, int length)
{
    const unsigned char polynomial = 0x07; // CRC-8 polynomial

    unsigned char crc = 0;

    for (int i = 0; i < length; i++)
    {
        crc ^= data[i];

        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ polynomial;
            else
                crc <<= 1;
        }
    }

    return crc;
}
