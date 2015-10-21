#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T22:07:42
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_phonebookunittesttest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += C++11

TEMPLATE = app

INCLUDEPATH += ../..


SOURCES += tst_phonebookunittesttest.cpp \
    ../../PhoneBook.cpp \
    ../../CSVParser.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../PhoneBook.hpp \
    ../../CSVParser.hpp \
    ../../Contact.hpp
