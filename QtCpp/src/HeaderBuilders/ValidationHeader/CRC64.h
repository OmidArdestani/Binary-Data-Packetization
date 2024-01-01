#ifndef CCRC64_H
#define CCRC64_H
#include <HeaderBuilders/HeaderBuilder.h>

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
};
}
}
#endif
