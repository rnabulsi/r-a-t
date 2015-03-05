#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T18:44:18
#
#-------------------------------------------------

include(../config/config.pri)

QT       += testlib
QT       -= gui

TARGET = test_common
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += testcase

TEMPLATE = app

SOURCES += test_node.cpp \
    test_main.cpp \
    test_node_binary_search.cpp \
    test_node_hash_table.cpp \
    test_node_extensive_tree.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test_node.h \
    test_node_binary_search.h \
    test_node_hash_table.h \
    test_node_extensive_tree.h

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
