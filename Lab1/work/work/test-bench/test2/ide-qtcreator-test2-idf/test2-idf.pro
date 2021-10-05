QT       += core
QT       -= gui

TARGET = test2
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
    ../src/app/statemachine02.cpp \
    ../src/app/testfactory02.cpp

HEADERS += \
    ../src/app/statemachine02.h \
    ../src/app/testfactory02.h \
    config/xf-port-config.h
