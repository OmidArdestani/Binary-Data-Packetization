#include "CRC64.h"

HeaderBuilder::ValidationHeader::CCRC64::CCRC64():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC64::BuildHeader(const char *body_data, int size, char *result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CCRC64::CheckHeader(const char *packet_data, int size)
{
    return false;
}
