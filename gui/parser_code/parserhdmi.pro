#-------------------------------------------------
#
# Project created by QtCreator 2018-09-10T13:48:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parserhdmi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    parser.h \
    parser_global.h \
    version.h

FORMS    += mainwindow.ui

LIBS += "..\build-parserhdmi-Desktop_Qt_5_6_3_MinGW_32bit-Debug\debug\parser.dll"
LIBS += "..\build-parserhdmi-Desktop_Qt_5_6_3_MinGW_32bit-Release\release\parser.dll"
