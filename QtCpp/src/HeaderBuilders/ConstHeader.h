#ifndef CCONSTHEADER_H
#define CCONSTHEADER_H
#include <string>
#include <iostream>

#include "HeaderBuilder.h"

#define DEFAULT_CONST_HEADER "AABBCCDD"
#define DEFAULT_CONST_HEADER_SIZE (int)std::strlen(DEFAULT_CONST_HEADER)

namespace HeaderBuilder{
class CConstHeader:public IHeaderBuilder
{
public:
    CConstHeader(const char* header = DEFAULT_CONST_HEADER, int size = DEFAULT_CONST_HEADER_SIZE);

private:
    const char* ConstHeader = nullptr;
    int ConstHeaderSize = -1;

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *result_buffer, int& result_size) override;
    bool CheckHeader(const char *packet_data, int size) override;
};
}
#endif
