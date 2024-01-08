#ifndef CHASH_H
#define CHASH_H
#include <HeaderBuilders/HeaderBuilder.h>

namespace HeaderBuilder{
namespace ValidationHeader {
class CHashSHA256:public IHeaderBuilder
{
public:
    CHashSHA256();

    // IHeaderBuilder interface
public:
    void BuildHeader(const char *body_data, int size, char *&result_buffer, int &result_size) override;
    bool CheckHeader(const char *packet_data, int size, char*& result_buffer, int& result_size) override;
    EHeaderType GetType() override{return EHeaderType::Hash;}

private:
    void CalcSha256(const char *input, int size, char *&result, int result_size);
};
}
}
#endif
