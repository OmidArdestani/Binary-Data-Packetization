#include "CRC32.h"

HeaderBuilder::ValidationHeader::CCRC32::CCRC32():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC32::BuildHeader(const char *body_data, int size, char *result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CCRC32::CheckHeader(const char *packet_data, int size)
{
    return false;
}
