#-------------------------------------------------
#
# Project created by QtCreator 2018-09-13T18:49:12
#
#-------------------------------------------------

QT       -= gui

TARGET = parser
TEMPLATE = lib

DEFINES += PARSER_LIBRARY

SOURCES += parser.cpp

HEADERS += parser.h\
        parser_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
