#-------------------------------------------------
#
# Project created by QtCreator 2015-03-08T22:26:11
#
#-------------------------------------------------

QT       -= gui
QT       += sql

TARGET = model
TEMPLATE = lib
CONFIG += staticlib

include(../config/config.pri)

HEADERS += node.h \
           letternode.h \
           resultnode.h \
           model.h \
    rawdata.hpp


SOURCES += node.cpp \
           letternode.cpp \
           resultnode.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../sql/release/ -lsql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../sql/debug/ -lsql
else:unix: LIBS += -L$$OUT_PWD/../sql/ -lsql

INCLUDEPATH += $$PWD/../sql
DEPENDPATH += $$PWD/../sql

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../sql/release/libsql.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../sql/debug/libsql.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../sql/release/sql.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../sql/debug/sql.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../sql/libsql.a
