#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T20:18:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Quadranter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    verticallabel.cpp \
    mylistview.cpp \
    mystringlistmodel.cpp

HEADERS  += mainwindow.h \
    verticallabel.h \
    mylistview.h \
    mystringlistmodel.h

FORMS    += mainwindow.ui

DISTFILES += \
    settings.cfg
