#include "ConstHeader.h"

HeaderBuilder::CConstHeader::CConstHeader(const char *header, int size):
    IHeaderBuilder(),
    ConstHeader(header),
    ConstHeaderSize(size)
{

}

void HeaderBuilder::CConstHeader::BuildHeader(char *body_data, int size, char *result_buffer, int &result_size)
{
    result_buffer = static_cast<char*>(std::malloc(size + ConstHeaderSize));
    std::memcpy(result_buffer,ConstHeader,ConstHeaderSize);
    std::memcpy(result_buffer + ConstHeaderSize,body_data,size);
    result_size = size + ConstHeaderSize;
}

bool HeaderBuilder::CConstHeader::CheckHeader(char *packet_data, int size)
{
    int const_header_index = 0;

    for(int i = 0; i < size; ++i)
    {
        if(*(packet_data + i) == *(ConstHeader + const_header_index))
        {
            const_header_index++;
        }

        if(const_header_index == ConstHeaderSize)
            return true;
    }

    return false;
}
