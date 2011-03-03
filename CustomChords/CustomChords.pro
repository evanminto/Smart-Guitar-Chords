#-------------------------------------------------
#
# Project created by QtCreator 2011-02-04T19:51:24
#
#-------------------------------------------------

QT       += core gui

TARGET = CustomChords
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Chord.cpp \
    Note.cpp \
    Instrument.cpp \
    InstrumentDatabase.cpp \
    ChordDatabase.cpp \
    functions.cpp

HEADERS  += mainwindow.h \
    Chord.h \
    Note.h \
    Instrument.h \
    InstrumentDatabase.h \
    ChordDatabase.h \
    CustomGuitarChords.h \
    functions.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
