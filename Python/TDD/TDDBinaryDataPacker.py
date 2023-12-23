import unittest

class TDDBinaryDataPacker(unittest.TestCase):
	def Const_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def Const_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def Const_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def Const_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def Const_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def Const_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def Const_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def Const_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash()))
	def Const_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def Const_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Const_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Const_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Const_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Const_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Const_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def Const_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::Const(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))
	def Checksum_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def Checksum_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def Checksum_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def Checksum_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def Checksum_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def Checksum_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def Checksum_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))       
	def Checksum_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def Checksum_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def Checksum_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def Checksum_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def Checksum_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def Checksum_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def Checksum_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))       
	def Checksum_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def Checksum_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def Checksum_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def Checksum_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def Checksum_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def Checksum_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def Checksum_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))       
	def Checksum_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def Checksum_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Checksum_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Checksum_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Checksum_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Checksum_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr())) 
	def Checksum_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))
	def Checksum_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def Checksum_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Checksum_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Checksum_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Checksum_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Checksum_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr())) 
	def Checksum_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))
	def Checksum_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def Checksum_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Checksum_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Checksum_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Checksum_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Checksum_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr())) 
	def Checksum_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))
	def Checksum_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def Checksum_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Checksum_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Checksum_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Checksum_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Checksum_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr()))
	def Checksum_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash()))
	def Checksum_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def Checksum_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Checksum_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def Checksum_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def Checksum_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def Checksum_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def Checksum_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))       
	def Checksum_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Checksum(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC8_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def CRC8_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def CRC8_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC8_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC8_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC8_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC8_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC8_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def CRC8_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def CRC8_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC8_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC8_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC8_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC8_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC8_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def CRC8_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def CRC8_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC8_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC8_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC8_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC8_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC8_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def CRC8_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC8_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def CRC8_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def CRC8_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def CRC8_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def CRC8_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))       
	def CRC8_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def CRC8_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC8_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def CRC8_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def CRC8_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def CRC8_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def CRC8_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))       
	def CRC8_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def CRC8_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC8_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC8_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def CRC8_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def CRC8_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def CRC8_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))       
	def CRC8_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def CRC8_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC8_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8())) 
	def CRC8_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC8_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC8_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC8_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr()))   
	def CRC8_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash())) 
	def CRC8_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def CRC8_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC8_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC8_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC8_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC8_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC8_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC8_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC8(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC16_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def CRC16_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC16_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC16_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC16_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC16_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC16_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC16_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC16_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def CRC16_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC16_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC16_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC16_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC16_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC16_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC16_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC16_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def CRC16_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC16_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC16_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC16_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC16_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC16_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC16_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC16_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def CRC16_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC16_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC16_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC16_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC16_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC16_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC16_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC16_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def CRC16_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC16_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC16_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC16_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC16_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC16_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC16_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC16_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def CRC16_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC16_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC16_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC16_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC16_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC16_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC16_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC16_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def CRC16_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC16_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC16_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC16_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC16_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC16_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr())) 
	def CRC16_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC16_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def CRC16_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))   
	def CRC16_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC16_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC16_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC16_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC16_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC16_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC16(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC32_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def CRC32_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC32_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC32_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC32_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC32_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC32_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC32_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC32_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def CRC32_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC32_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC32_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC32_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC32_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC32_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC32_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC32_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def CRC32_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC32_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC32_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC32_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC32_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC32_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC32_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC32_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def CRC32_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC32_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC32_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC32_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC32_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC32_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC32_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC32_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def CRC32_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC32_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC32_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC32_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC32_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC32_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC32_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC32_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def CRC32_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC32_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC32_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC32_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC32_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC32_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC32_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC32_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def CRC32_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC32_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC32_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC32_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC32_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC32_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr())) 
	def CRC32_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC32_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def CRC32_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))   
	def CRC32_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC32_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC32_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC32_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC32_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC32_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC32(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC64_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def CRC64_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC64_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC64_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC64_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC64_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC64_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC64_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC64_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def CRC64_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC64_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC64_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC64_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC64_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC64_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC64_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC64_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def CRC64_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def CRC64_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC64_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC64_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC64_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC64_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC64_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC64_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def CRC64_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC64_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC64_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC64_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC64_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC64_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC64_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC64_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def CRC64_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC64_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC64_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC64_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC64_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC64_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC64_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC64_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def CRC64_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC64_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))     
	def CRC64_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))   
	def CRC64_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))   
	def CRC64_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))   
	def CRC64_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))       
	def CRC64_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))     
	def CRC64_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def CRC64_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def CRC64_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC64_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC64_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC64_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC64_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr())) 
	def CRC64_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash()))
	def CRC64_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def CRC64_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))   
	def CRC64_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def CRC64_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def CRC64_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def CRC64_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def CRC64_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def CRC64_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::CRC64(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def XOr_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))
	def XOr_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def XOr_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def XOr_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def XOr_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def XOr_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))
	def XOr_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def XOr_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def XOr_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def XOr_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def XOr_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))
	def XOr_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def XOr_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def XOr_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def XOr_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def XOr_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum())) 
	def XOr_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))       
	def XOr_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))       
	def XOr_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))       
	def XOr_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def XOr_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum())) 
	def XOr_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))       
	def XOr_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))       
	def XOr_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))       
	def XOr_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def XOr_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum())) 
	def XOr_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))       
	def XOr_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))       
	def XOr_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))
	def XOr_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))
	def XOr_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def XOr_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def XOr_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8()))   
	def XOr_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16())) 
	def XOr_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32())) 
	def XOr_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64())) 
	def XOr_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr()))     
	def XOr_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash()))   
	def XOr_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def XOr_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def XOr_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def XOr_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def XOr_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def XOr_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def XOr_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def XOr_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::XOr(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))
	def Hash_RSA_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::Const()))
	def Hash_RSA_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def Hash_RSA_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Hash_RSA_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Hash_RSA_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Hash_RSA_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Hash_RSA_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_RSA_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::RSA(),new HeaderBuilder::ValidationHeader::Hash()))
	def Hash_AES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::Const()))
	def Hash_AES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def Hash_AES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Hash_AES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Hash_AES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Hash_AES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Hash_AES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_AES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::AES(),new HeaderBuilder::ValidationHeader::Hash()))
	def Hash_DES_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::Const()))
	def Hash_DES_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Checksum()))       
	def Hash_DES_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Hash_DES_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Hash_DES_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Hash_DES_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Hash_DES_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_DES_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::DES(),new HeaderBuilder::ValidationHeader::Hash()))
	def Hash_TwoFish_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::Const()))
	def Hash_TwoFish_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Hash_TwoFish_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def Hash_TwoFish_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def Hash_TwoFish_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def Hash_TwoFish_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def Hash_TwoFish_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_TwoFish_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Encryption::TwoFish(),new HeaderBuilder::ValidationHeader::Hash()))
	def Hash_	defLATE_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::Const()))
	def Hash_	defLATE_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Hash_	defLATE_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def Hash_	defLATE_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def Hash_	defLATE_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def Hash_	defLATE_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def Hash_	defLATE_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_	defLATE_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::	defLATE(),new HeaderBuilder::ValidationHeader::Hash()))       
	def Hash_Huffman_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::Const()))
	def Hash_Huffman_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Hash_Huffman_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC8()))       
	def Hash_Huffman_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC16()))     
	def Hash_Huffman_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC32()))     
	def Hash_Huffman_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::CRC64()))     
	def Hash_Huffman_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_Huffman_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Huffman(),new HeaderBuilder::ValidationHeader::Hash()))       
	def Hash_Arithmetic_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::Const()))
	def Hash_Arithmetic_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Checksum()))
	def Hash_Arithmetic_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC8())) 
	def Hash_Arithmetic_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Hash_Arithmetic_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Hash_Arithmetic_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Hash_Arithmetic_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::XOr()))   
	def Hash_Arithmetic_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::Arithmetic(),new HeaderBuilder::ValidationHeader::Hash())) 
	def Hash_JPEG_Const(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::Const()))
	def Hash_JPEG_Checksum(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Checksum()))     
	def Hash_JPEG_CRC8(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC8()))
	def Hash_JPEG_CRC16(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC16()))
	def Hash_JPEG_CRC32(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC32()))
	def Hash_JPEG_CRC64(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::CRC64()))
	def Hash_JPEG_XOr(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::XOr()))
	def Hash_JPEG_Hash(self):
		VerifyResult(BuildPacker(new HeaderBuilder::ValidationHeader::Hash(),new PacketBuilder::Compressor::JPEG(),new HeaderBuilder::ValidationHeader::Hash()))