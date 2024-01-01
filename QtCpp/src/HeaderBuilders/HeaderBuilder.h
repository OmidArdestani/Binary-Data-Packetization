#ifndef IHEADERBUILDER_H
#define IHEADERBUILDER_H

enum class EHeaderType{
    ConstHeader,
    Checksum,
    Crc8,Crc16,Crc32,Crc64,
    Hash,
    Xor
};

class IHeaderBuilder
{
public:
    virtual void BuildHeader(const char* body_data, int size, char*& result_buffer, int& result_size) = 0;
    virtual bool CheckHeader(const char* packet_data, int size, char*& result_buffer, int& result_size) = 0;
    virtual EHeaderType GetType() = 0;

    enum class EHeaderPostion{
        StartOfFrame, // start of frame
        EndOfFrame    // end of frame
    };
    void SetHeaderPosition(EHeaderPostion hp){HeaderPostion = hp;}

protected:
    EHeaderPostion HeaderPostion = EHeaderPostion::StartOfFrame;
};
#endif
