#-------------------------------------------------
#
# Project created by QtCreator 2017-11-29 T00:08:14
#
#-------------------------------------------------

QT       += core gui network multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += Main.cpp\
    ClientWindow.cpp \
    Client.cpp

HEADERS  +=\
    ClientWindow.h \
    Client.h

FORMS    +=\
    ClientWindow.ui
