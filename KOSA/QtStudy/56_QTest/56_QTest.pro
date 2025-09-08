QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    dog.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    dog.h \
    widget.h
