#include "ConstHeader.h"

HeaderBuilder::CConstHeader::CConstHeader(const char *header, int size):
    IHeaderBuilder(),
    ConstHeader(header),
    ConstHeaderSize(size)
{

}

void HeaderBuilder::CConstHeader::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
    auto result_buffer_temp = static_cast<char*>(std::malloc(size + ConstHeaderSize));

    std::memcpy(result_buffer_temp,ConstHeader,ConstHeaderSize);
    std::memcpy(result_buffer_temp + ConstHeaderSize,body_data,size);

    result_size = size + ConstHeaderSize;
    result_buffer = result_buffer_temp;
}

bool HeaderBuilder::CConstHeader::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    int const_header_index = 0;

    for(int i = 0; i < size; ++i)
    {
        if(packet_data[i] == ConstHeader[const_header_index])
        {
            const_header_index++;
        }

        if(const_header_index == ConstHeaderSize)
        {
            auto result_size_temp = size - ConstHeaderSize;
            auto result_buffer_temp = static_cast<char*>(std::malloc(result_size_temp));
            std::memcpy(result_buffer_temp, (packet_data + i + 1), result_size_temp);

            result_size = result_size_temp;
            result_buffer = result_buffer_temp;
            return true;
        }
    }

    return false;
}
