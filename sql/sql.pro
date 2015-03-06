#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T13:48:07
#
#-------------------------------------------------

QT       += sql
QT       -= gui

TARGET = sql
TEMPLATE = lib
CONFIG += staticlib

include(../config/config.pri)

SOURCES += sqlmanager.cpp

HEADERS += sqlmanager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
