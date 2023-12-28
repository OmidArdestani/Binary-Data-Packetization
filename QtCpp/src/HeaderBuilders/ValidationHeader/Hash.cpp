#include "Hash.h"

HeaderBuilder::ValidationHeader::CHash::CHash():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CHash::BuildHeader(const char *body_data, int size, char *result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CHash::CheckHeader(const char *packet_data, int size)
{
    return false;
}
