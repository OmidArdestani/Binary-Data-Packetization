QT += core

TARGET   = BinaryDataPackerLib
TEMPLATE = lib
CONFIG  += staticlib

SOURCES +=\
	BinaryDataPacker.cpp \
	HeaderBuilders/ConstHeader.cpp \
	HeaderBuilders/ValidationHeader/CRC16.cpp \
	HeaderBuilders/ValidationHeader/CRC32.cpp \
	HeaderBuilders/ValidationHeader/CRC64.cpp \
	HeaderBuilders/ValidationHeader/CRC8.cpp \
	HeaderBuilders/ValidationHeader/Checksum.cpp \
	HeaderBuilders/ValidationHeader/Hash.cpp \
	HeaderBuilders/ValidationHeader/XOR.cpp \
	PacketBuilders/Compressors/Arithmetic.cpp \
	PacketBuilders/Compressors/DEFLATE.cpp \
	PacketBuilders/Compressors/Huffman.cpp \
	PacketBuilders/Compressors/JPEG.cpp \
	PacketBuilders/Encryptions/AES.cpp \
	PacketBuilders/Encryptions/DES.cpp \
	PacketBuilders/Encryptions/RSA.cpp \
	PacketBuilders/Encryptions/TwoFish.cpp
	
HEADERS +=\
	BinaryDataPacker.h \
	HeaderBuilders/ConstHeader.h \
	HeaderBuilders/HeaderBuilder.h \
	HeaderBuilders/ValidationHeader/CRC16.h \
	HeaderBuilders/ValidationHeader/CRC32.h \
	HeaderBuilders/ValidationHeader/CRC64.h \
	HeaderBuilders/ValidationHeader/CRC8.h \
	HeaderBuilders/ValidationHeader/Checksum.h \
	HeaderBuilders/ValidationHeader/Hash.h \
	HeaderBuilders/ValidationHeader/XOR.h \
	PacketBuilders/Compressors/Arithmetic.h \
	PacketBuilders/Compressors/DEFLATE.h \
	PacketBuilders/Compressors/Huffman.h \
	PacketBuilders/Compressors/JPEG.h \
	PacketBuilders/Encryptions/AES.h \
	PacketBuilders/Encryptions/DES.h \
	PacketBuilders/Encryptions/RSA.h \
	PacketBuilders/Encryptions/TwoFish.h \
	PacketBuilders/PacketBuilder.h
