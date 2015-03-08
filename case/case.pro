#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T16:44:09
#
#-------------------------------------------------

QT       -= gui

TARGET = case
TEMPLATE = lib
CONFIG += staticlib

include(../config/config.pri)

SOURCES += abstractgraph.cpp

HEADERS += abstractgraph.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
