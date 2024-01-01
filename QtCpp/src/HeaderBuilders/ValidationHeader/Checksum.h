#ifndef CCHECKSUM_H
#define CCHECKSUM_H

#include <HeaderBuilders/HeaderBuilder.h>


namespace HeaderBuilder{
namespace ValidationHeader {
class CChecksum:public IHeaderBuilder
{
public:
    CChecksum();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Checksum;}
};
}
}

#endif
