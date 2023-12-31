#ifndef CHASH_H
#define CHASH_H
#include <HeaderBuilders/HeaderBuilder.h>

namespace HeaderBuilder{
namespace ValidationHeader {
class CHash:public IHeaderBuilder
{
public:
    CHash();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
};
}
}
#endif
