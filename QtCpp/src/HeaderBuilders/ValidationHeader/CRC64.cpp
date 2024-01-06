#include "CRC64.h"

HeaderBuilder::ValidationHeader::CCRC64::CCRC64():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC64::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto crc_value = CalculateCRC64(body_data, size);
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

bool HeaderBuilder::ValidationHeader::CCRC64::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    if(HeaderPostion == EHeaderPostion::StartOfFrame)
    {
        auto packet_crc_value = *reinterpret_cast<const uint64_t*>(packet_data);
        int crc_size = sizeof(packet_crc_value);
        auto crc_value = CalculateCRC64(packet_data + crc_size, size - crc_size);

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

uint64_t HeaderBuilder::ValidationHeader::CCRC64::CalculateCRC64(const char* data, size_t length)
{
    const uint64_t polynomial = 0xC96C5795D7870F42ULL; // CRC-64 polynomial

    uint64_t crc = 0xFFFFFFFFFFFFFFFFULL;

    for (size_t i = 0; i < length; i++)
    {
        crc ^= static_cast<uint64_t>(data[i]) << 56;

        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x8000000000000000ULL)
                crc = (crc << 1) ^ polynomial;
            else
                crc <<= 1;
        }
    }

    return crc ^ 0xFFFFFFFFFFFFFFFFULL;
}
