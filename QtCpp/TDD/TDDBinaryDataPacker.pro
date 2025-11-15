QT += core widgets testlib


CONFIG += c++17

SOURCES += \
        TDDBinaryDataPacker.cpp \
        ../src/BinaryDataPacker.cpp

HEADERS += \
        ../src/BinaryDataPacker.h

# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Release/release/ -lBinaryDataPackerLib
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Debug/debug/ -lBinaryDataPackerLib

INCLUDEPATH += $$PWD/../src
# DEPENDPATH += $$PWD/../src

# win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Release/release/libBinaryDataPackerLib.a
# else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Debug/debug/libBinaryDataPackerLib.a
# else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Release/release/BinaryDataPackerLib.lib
# else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-BinaryDataPacker-Desktop_Qt_6_6_1_MSVC2019_64bit-Debug/debug/BinaryDataPackerLib.lib
