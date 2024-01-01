#ifndef CCRC16_H
#define CCRC16_H
#include <HeaderBuilders/HeaderBuilder.h>

namespace HeaderBuilder{
namespace ValidationHeader {
class CCRC16:public IHeaderBuilder
{
public:
    CCRC16();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Crc16;}
};
}
}
#endif
