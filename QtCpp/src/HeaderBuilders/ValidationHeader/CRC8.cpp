#include "CRC8.h"

HeaderBuilder::ValidationHeader::CCRC8::CCRC8():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC8::BuildHeader(const char *body_data, int size, char *result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CCRC8::CheckHeader(const char *packet_data, int size)
{
    return false;
}
