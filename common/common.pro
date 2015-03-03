#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T22:48:54
#
#-------------------------------------------------

QT       -= gui

TARGET = common
TEMPLATE = lib

include(../config/config.pri)

DEFINES += COMMON_LIBRARY

HEADERS += common.h\
        common_global.h \
    node.h \
    letternode.h \
    resultnode.h

SOURCES += \
    common.cpp \
    node.cpp \
    letternode.cpp \
    resultnode.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
