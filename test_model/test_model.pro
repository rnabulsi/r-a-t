#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T18:44:18
#
#-------------------------------------------------

include(../config/config.pri)

QT       += testlib
QT       -= gui

TARGET = test_model
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += testcase

TEMPLATE = app

SOURCES += test_node.cpp \
    test_main.cpp \
    test_node_binary_search.cpp \
    test_node_hash_table.cpp \
    test_node_extensive_tree.cpp \
    test_letternode.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test_node.h \
    test_node_binary_search.h \
    test_node_hash_table.h \
    test_node_extensive_tree.h \
    test_letternode.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../model/release/ -lmodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../model/debug/ -lmodel
else:unix: LIBS += -L$$OUT_PWD/../model/ -lmodel

INCLUDEPATH += $$PWD/../model
DEPENDPATH += $$PWD/../model

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/release/libmodel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/debug/libmodel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/release/model.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/debug/model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../model/libmodel.a