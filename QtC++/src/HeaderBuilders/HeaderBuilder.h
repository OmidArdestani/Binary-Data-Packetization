
class IHeaderBuilder
{
public:
    virtual void BuildHeader(char* body_data, int size, char* result_buffer, int& result_size) = 0;
    virtual bool CheckHeader(char* packet_data, int size) = 0;
};
