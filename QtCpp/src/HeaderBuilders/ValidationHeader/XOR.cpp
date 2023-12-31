#include "XOR.h"

HeaderBuilder::ValidationHeader::CXOR::CXOR():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CXOR::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CXOR::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    return false;
}
