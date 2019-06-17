#-------------------------------------------------
#
# Project created by QtCreator 2019-05-30T09:32:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = slot_DMAread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawing.cpp \
    subwindow.cpp

HEADERS  += mainwindow.h \
    drawing.h \
    subwindow.h

FORMS    += mainwindow.ui \
    drawing.ui \
    subwindow.ui
