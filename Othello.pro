#-------------------------------------------------
#
# Project created by QtCreator 2016-01-02T13:47:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Othello
TEMPLATE = app


SOURCES += main.cpp\
        Othello.cpp \
    Board.cpp

HEADERS  += Othello.h \
    Board.h

CONFIG += c++11
