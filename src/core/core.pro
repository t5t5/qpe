include(../../qpe-include.pri)

QT += core
QT -= gui

TARGET = qpecore
TEMPLATE = lib
CONFIG += $$QPE_CORE_CONFIG_STATICLIB

DEFINES += QPE_CORE_LIB

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj
RCC_DIR = ./tmp/rcc
UI_DIR = ./tmp/ui
DESTDIR = $$QPE_CORE_BUILD_DIR

OTHER_FILES += \
    doc/core.qdocconf

documentTarget($$PWD/doc/core.qdocconf)
