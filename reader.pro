#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T10:50:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reader
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++14

SOURCES += main.cpp\
        reader.cpp

HEADERS  += reader.hpp

FORMS    += reader.ui
