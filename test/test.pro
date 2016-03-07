QT += core testlib
QT -= gui

TARGET = test
CONFIG += c++14 console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    /usr/src/gtest/src/gtest-all.cc \
    /usr/src/gmock/src/gmock_main.cc \
    /usr/src/gmock/src/gmock-all.cc \
    introspectionparsertest.cpp


#HEADERS += \

INCLUDEPATH += /usr/src/gtest /usr/src/gmock

include(../AllJoyn-Introspector-Cpp.pri)
include(../core/core.pri)

DISTFILES += \
    example.txt