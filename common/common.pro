#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T22:48:54
#
#-------------------------------------------------

QT       -= gui
QT       += sql

TARGET = common
TEMPLATE = lib
CONFIG += staticlib

include(../config/config.pri)

DEFINES += COMMON_LIBRARY

HEADERS += common.h\
           common_global.h \
           sarf.h \
           atmprogress.h \
           emptyprogress.h \
           atmineconfiguration.h

SOURCES += \
           sarf.cpp \
           atmineconfiguration.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../case/release/ -lcase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../case/debug/ -lcase
else:unix: LIBS += -L$$OUT_PWD/../case/ -lcase

INCLUDEPATH += $$PWD/../case
DEPENDPATH += $$PWD/../case

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../case/release/libcase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../case/debug/libcase.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../case/release/case.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../case/debug/case.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../case/libcase.a

