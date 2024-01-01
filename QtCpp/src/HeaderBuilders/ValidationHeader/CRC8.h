#ifndef CCRC8_H
#define CCRC8_H
#include <HeaderBuilders/HeaderBuilder.h>

namespace HeaderBuilder{
namespace ValidationHeader {
class CCRC8:public IHeaderBuilder
{
public:
    CCRC8();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Crc8;}
};
}
}
#endif
