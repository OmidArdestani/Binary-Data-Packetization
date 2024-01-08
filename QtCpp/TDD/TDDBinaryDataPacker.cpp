#include <QObject>
#include <QTest>
#include <BinaryDataPacker.h>



class TDDBinaryDataPacker: public QObject
{
    Q_OBJECT

private:
    const char* RawData = "this is a message for packaging test.";
    const int RawDataSize = (int)strlen(RawData);

    CBinaryDataPacketizer* BuildPacker(IHeaderBuilder* header,IPacketBuilder* body, IHeaderBuilder* footer)
    {
        CBinaryDataPacketizer* bdp = new CBinaryDataPacketizer();
        bdp->SetSOFBuilder(header);
        bdp->AddPacketBuilder(body);
        // bdp->AddEOFBuilder(footer);
        return bdp;
    }

    void VerifyResult(CBinaryDataPacketizer* bdp)
    {
        char* packet_to_send = nullptr;
        int packet_size = -1;
        bdp->GetPacket(RawData, RawDataSize, packet_to_send, packet_size);

        QCOMPARE_GE(packet_size, 0); // check the size greater than 0

        char* unpacked_data = nullptr;
        int unpacked_data_size = -1;
        bdp->UnpackData(packet_to_send, packet_size, unpacked_data, unpacked_data_size);

        QCOMPARE_EQ(unpacked_data_size, RawDataSize);

        // Convert char* to QString for comparison
        QString expectedString = QString::fromUtf8(RawData, RawDataSize);
        QString actualString = QString::fromUtf8(unpacked_data, unpacked_data_size);

        // Compare the strings using QCOMPARE
        QCOMPARE(expectedString, actualString);

        delete bdp;
    }
private slots:

    // ------------------------------------
    //The test method name strcuture is (HeaderBuilderName_PacketBuilderName_FooterBuilderName)
    // ------------------------------------
    void Const_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void Const_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void Const_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void Const_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void Const_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void Const_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void Const_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void Const_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Const_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void Const_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Const_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Const_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Const_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Const_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Const_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Const_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::CConstHeader(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Checksum_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void Checksum_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Checksum_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Checksum_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Checksum_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Checksum_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Checksum_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Checksum_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CChecksum(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC8_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void CRC8_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC8_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC8_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC8_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC8_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC8_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC8_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC8(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC16_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void CRC16_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC16_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC16_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC16_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC16_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC16_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC16_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC16(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC32_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void CRC32_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC32_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC32_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC32_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC32_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC32_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC32_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC32(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void CRC64_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void CRC64_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void CRC64_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void CRC64_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void CRC64_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void CRC64_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void CRC64_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void CRC64_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CCRC64(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void XOr_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void XOr_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void XOr_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void XOr_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void XOr_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void XOr_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void XOr_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void XOr_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CXOR(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_RSA_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_RSA_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_RSA_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_RSA_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_RSA_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_RSA_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_RSA_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_RSA_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CRSA(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_AES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_AES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_AES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_AES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_AES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_AES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_AES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_AES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CAES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_DES_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_DES_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_DES_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_DES_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_DES_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_DES_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_DES_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_DES_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CDES(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_TwoFish_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_TwoFish_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_TwoFish_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_TwoFish_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_TwoFish_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_TwoFish_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_TwoFish_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_TwoFish_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Encryption::CTwoFish(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_DEFLATE_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_DEFLATE_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_DEFLATE_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_DEFLATE_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_DEFLATE_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_DEFLATE_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_DEFLATE_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_DEFLATE_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CDEFLATE(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_Huffman_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_Huffman_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_Huffman_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_Huffman_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_Huffman_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_Huffman_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_Huffman_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_Huffman_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CHuffman(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_Arithmetic_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_Arithmetic_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_Arithmetic_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_Arithmetic_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_Arithmetic_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_Arithmetic_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_Arithmetic_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_Arithmetic_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CArithmetic(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }
    void Hash_JPEG_ConstHeader(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::CConstHeader()));
    }
    void Hash_JPEG_Checksum(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CChecksum()));
    }
    void Hash_JPEG_CRC8(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC8()));
    }
    void Hash_JPEG_CRC16(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC16()));
    }
    void Hash_JPEG_CRC32(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC32()));
    }
    void Hash_JPEG_CRC64(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CCRC64()));
    }
    void Hash_JPEG_XOr(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CXOR()));
    }
    void Hash_JPEG_Hash(){
        VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CHashSHA256(),new PacketBuilder::Compressor::CJPEG(),new HeaderBuilder::ValidationHeader::CHashSHA256()));
    }

};

QTEST_MAIN(TDDBinaryDataPacker)
#include "TDDBinaryDataPacker.moc"
