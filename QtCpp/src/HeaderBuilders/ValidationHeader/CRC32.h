#ifndef CCRC32_H
#define CCRC32_H
#include <HeaderBuilders/HeaderBuilder.h>

namespace HeaderBuilder{
namespace ValidationHeader {
class CCRC32:public IHeaderBuilder
{
public:
    CCRC32();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size) override;
};
}
}
#endif
