#include "CRC16.h"


HeaderBuilder::ValidationHeader::CCRC16::CCRC16():IHeaderBuilder()
{

}


void HeaderBuilder::ValidationHeader::CCRC16::BuildHeader(const char *body_data, int size, char *result_buffer, int &result_size)
{
}

bool HeaderBuilder::ValidationHeader::CCRC16::CheckHeader(const char *packet_data, int size)
{
    return false;
}
