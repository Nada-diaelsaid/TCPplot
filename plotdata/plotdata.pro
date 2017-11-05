#-------------------------------------------------
#
# Project created by QtCreator 2017-11-01T22:22:11
#
#-------------------------------------------------

QT       += core gui printsupport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plotdata
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    socket.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    socket.h

FORMS    += mainwindow.ui

QT += printsupport

