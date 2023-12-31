#include "Checksum.h"

HeaderBuilder::ValidationHeader::CChecksum::CChecksum():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CChecksum::BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CChecksum::CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size)
{
    return false;
}
