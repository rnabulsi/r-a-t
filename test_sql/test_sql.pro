#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T18:25:31
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui

TARGET = test_sqlmanager
CONFIG   += console
CONFIG   -= app_bundle

include(../config/config.pri)

TEMPLATE = app

HEADERS += \
    test_sqlmanager.h

SOURCES += \
    test_sqlmanager.cpp \
    test_main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../common/release/ -lcommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../common/debug/ -lcommon
else:unix: LIBS += -L$$OUT_PWD/../common/ -lcommon

INCLUDEPATH += $$PWD/../common
DEPENDPATH += $$PWD/../common

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/libcommon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/libcommon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/release/common.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../common/debug/common.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../common/libcommon.a
