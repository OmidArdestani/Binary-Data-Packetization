#ifndef CCRC64_H
#define CCRC64_H
#include <HeaderBuilders/HeaderBuilder.h>
#include <iostream>

namespace HeaderBuilder{
namespace ValidationHeader {
class CCRC64:public IHeaderBuilder
{
public:
    CCRC64();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Crc64;}

private:
    uint64_t CalculateCRC64(const char *data, size_t length);
};
}
}
#endif
