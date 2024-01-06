#ifndef CXOR_H
#define CXOR_H
#include <HeaderBuilders/HeaderBuilder.h>
#include <iostream>

namespace HeaderBuilder{
namespace ValidationHeader {
class CXOR:public IHeaderBuilder
{
public:
    CXOR();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Xor;}

private:
    unsigned char CalculateXOR(const char *data, int length);
};
}
}
#endif
