include(../../qpe-include.pri)

QT += core
QT -= gui

CONFIG += c++11

TARGET = qpelogger
TEMPLATE = lib
CONFIG += $$QPE_LOGGER_CONFIG_STATICLIB

DEFINES += QPE_LOGGER_LIB

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj
RCC_DIR = ./tmp/rcc
UI_DIR = ./tmp/ui
DESTDIR = $$QPE_LOGGER_BUILD_DIR

LIBS += -L$$QPE_CORE_BUILD_DIR -lqpecore

include(appenders/appenders.pri)
include(core/core.pri)
include(filters/filters.pri)

OTHER_FILES += \
    doc/logger.qdocconf

documentTarget($$PWD/doc/logger.qdocconf)
