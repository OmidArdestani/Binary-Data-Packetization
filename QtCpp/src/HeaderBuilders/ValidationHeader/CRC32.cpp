#include "CRC32.h"

HeaderBuilder::ValidationHeader::CCRC32::CCRC32():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC32::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto crc_value = CalculateCRC32(body_data, size);
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

bool HeaderBuilder::ValidationHeader::CCRC32::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto packet_crc_value = *reinterpret_cast<const uint32_t*>(packet_data);
        int crc_size = sizeof(packet_crc_value);
        auto crc_value = CalculateCRC32(packet_data + crc_size, size - crc_size);

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

uint32_t HeaderBuilder::ValidationHeader::CCRC32::CalculateCRC32(const char* data, size_t length)
{
    const uint32_t polynomial = 0xEDB88320; // CRC-32 polynomial

    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < length; i++)
    {
        crc ^= data[i];

        for (int j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ polynomial;
            else
                crc >>= 1;
        }
    }

    return crc ^ 0xFFFFFFFF;
}
