QT -= gui
QT += core xml

TARGET = core
CONFIG += c++14 staticlib

TEMPLATE = lib

SOURCES += \
    introspectionparser.cpp \
    alljoynnode.cpp

HEADERS += \
    introspectionparser.h \
    alljoynnode.h \
    joinedbussession_fw.h

include(../AllJoyn-Introspector-Cpp.pri)