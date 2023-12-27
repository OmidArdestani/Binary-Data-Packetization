#include "HeaderBuilder.h"
#include <string>
#include <iostream>


#define DEFAULT_CONST_HEADER "AABBCCDD"
#define DEFAULT_CONST_HEADER_SIZE (int)std::strlen(DEFAULT_CONST_HEADER)

namespace HeaderBuilder{
class CConstHeader:public IHeaderBuilder
{
public:

    CConstHeader(const char* header = "AABBCCDD", int size = DEFAULT_CONST_HEADER_SIZE);

private:
    const char* ConstHeader = nullptr;
    int ConstHeaderSize = -1;

    // IHeaderBuilder interface
public:
    void BuildHeader(char *body_data, int size, char *result_buffer, int& result_size) override;
    bool CheckHeader(char *packet_data, int size) override;
};
}
