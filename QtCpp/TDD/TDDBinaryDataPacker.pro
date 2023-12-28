QT += core widgets testlib


SOURCES +=\
        TDDBinaryDataPacker.cpp

SOURCES +=\
        ../src/BinaryDataPacker.cpp \
        ../src/HeaderBuilders/ConstHeader.cpp \
        ../src/HeaderBuilders/ValidationHeader/CRC16.cpp \
        ../src/HeaderBuilders/ValidationHeader/CRC32.cpp \
        ../src/HeaderBuilders/ValidationHeader/CRC64.cpp \
        ../src/HeaderBuilders/ValidationHeader/CRC8.cpp \
        ../src/HeaderBuilders/ValidationHeader/Checksum.cpp \
        ../src/HeaderBuilders/ValidationHeader/Hash.cpp \
        ../src/HeaderBuilders/ValidationHeader/XOR.cpp \
        ../src/PacketBuilders/Compressors/Arithmetic.cpp \
        ../src/PacketBuilders/Compressors/DEFLATE.cpp \
        ../src/PacketBuilders/Compressors/Huffman.cpp \
        ../src/PacketBuilders/Compressors/JPEG.cpp \
        ../src/PacketBuilders/Encryptions/AES.cpp \
        ../src/PacketBuilders/Encryptions/DES.cpp \
        ../src/PacketBuilders/Encryptions/RSA.cpp \
        ../src/PacketBuilders/Encryptions/TwoFish.cpp

HEADERS +=\
        ../src/BinaryDataPacker.h \
        ../src/HeaderBuilders/ConstHeader.h \
        ../src/HeaderBuilders/ValidationHeader/CRC16.h \
        ../src/HeaderBuilders/ValidationHeader/CRC32.h \
        ../src/HeaderBuilders/ValidationHeader/CRC64.h \
        ../src/HeaderBuilders/ValidationHeader/CRC8.h \
        ../src/HeaderBuilders/ValidationHeader/Checksum.h \
        ../src/HeaderBuilders/ValidationHeader/Hash.h \
        ../src/HeaderBuilders/ValidationHeader/XOR.h \
        ../src/HeaderBuilders/HeaderBuilder.h \
        ../src/PacketBuilders/Compressors/Arithmetic.h \
        ../src/PacketBuilders/Compressors/DEFLATE.h \
        ../src/PacketBuilders/Compressors/Huffman.h \
        ../src/PacketBuilders/Compressors/JPEG.h \
        ../src/PacketBuilders/Encryptions/AES.h \
        ../src/PacketBuilders/Encryptions/DES.h \
        ../src/PacketBuilders/Encryptions/RSA.h \
        ../src/PacketBuilders/Encryptions/TwoFish.h \
        ../src/PacketBuilders/PacketBuilder.h

# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Release/release/ -lBinaryDataPackerLib
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Debug/debug/ -lBinaryDataPackerLib

INCLUDEPATH += $$PWD/../src
# DEPENDPATH += $$PWD/../src

# win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Release/release/libBinaryDataPackerLib.a
# else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Debug/debug/libBinaryDataPackerLib.a
# else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Release/release/BinaryDataPackerLib.lib
# else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Debug/debug/BinaryDataPackerLib.lib
