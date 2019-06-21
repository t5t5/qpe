include(../../../qpe-include.pri)

QT += core testlib
QT -= gui

CONFIG += c++11

TARGET = test_crontimer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj
RCC_DIR = ./tmp/rcc
UI_DIR = ./tmp/ui
DESTDIR = $$QPE_BUILD_TEST_DIR

LIBS += -L$$QPE_CORE_BUILD_DIR -lqpecore

SOURCES += \
    test_crontimer.cpp
