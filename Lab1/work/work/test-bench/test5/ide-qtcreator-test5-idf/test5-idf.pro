QT       += core
QT       -= gui

TARGET = test5
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

DEFINES += TC_QTCREATOR
XF_PATH = ../../../src/simplified/xf

DEPENDPATH += . \

INCLUDEPATH += . \
    .. \
    ../src \
    $${XF_PATH}/include \
    ../../../src/mdw \
    ../../../src/platform/qt

include(common.pri)
include($${XF_PATH}/xf-core.pri)
include($${XF_PATH}/port/common/xf-port-common.pri)
include($${XF_PATH}/port/idf-qt/xf-port-idf-qt.pri)
include(../../../src/platform/qt/platform-qt.pri)

SOURCES += \
    ../src/main.cpp  \
    ../src/app/statemachine05a.cpp \
    ../src/app/statemachine05b.cpp \
    ../src/app/testfactory05.cpp \
    ../src/events/evrestart.cpp

HEADERS += \
    ../src/app/statemachine05a.h \
    ../src/app/statemachine05b.h \
    ../src/app/testfactory05.h \
    ../src/events/eventids.h \
    ../src/events/evrestart.h \
    config/xf-port-config.h
