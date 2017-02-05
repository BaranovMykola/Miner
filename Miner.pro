#-------------------------------------------------
#
# Project created by QtCreator 2017-02-04T11:43:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Miner
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        miner.cpp \
    cell.cpp \
    abstractcellstate.cpp \
    basiccellstate.cpp \
    steppedcellstate.cpp \
    gridfield.cpp \
    abstractcell.cpp \
    sun.cpp

HEADERS  += miner.h \
    cell.h \
    abstractcellstate.h \
    basiccellstate.h \
    steppedcellstate.h \
    gridfield.h \
    abstractcell.h \
    sun.h

FORMS    += miner.ui

RESOURCES += \
    resources.qrc

CONFIG += c++14
CONFIG += Sun
