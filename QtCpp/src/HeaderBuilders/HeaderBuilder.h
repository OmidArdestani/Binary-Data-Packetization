#ifndef IHEADERBUILDER_H
#define IHEADERBUILDER_H
class IHeaderBuilder
{
public:
    virtual void BuildHeader(const char* body_data, int size, char*& result_buffer, int& result_size) = 0;
    virtual bool CheckHeader(const char* packet_data, int size, char*& result_buffer, int& result_size) = 0;
};
#endif
