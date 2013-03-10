#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T14:10:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = oscillator-errors
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintwidget.cpp \
    simulation.cpp \
    qcustomplot.cpp \
    timeplot.cpp \
    phaseplot.cpp \
    errorplot.cpp

HEADERS  += mainwindow.h \
    paintwidget.h \
    simulation.h \
    qcustomplot.h \
    timeplot.h \
    phaseplot.h \
    errorplot.h

FORMS    += mainwindow.ui
