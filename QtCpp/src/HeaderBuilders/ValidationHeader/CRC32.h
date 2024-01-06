#ifndef CCRC32_H
#define CCRC32_H
#include <HeaderBuilders/HeaderBuilder.h>
#include <iostream>

namespace HeaderBuilder{
namespace ValidationHeader {
class CCRC32:public IHeaderBuilder
{
public:
    CCRC32();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Crc32;}

private:
    uint32_t CalculateCRC32(const char *data, size_t length);
};
}
}
#endif
