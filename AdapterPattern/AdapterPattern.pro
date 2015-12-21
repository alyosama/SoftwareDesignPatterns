TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    MallardDuck.cpp \
    TurkeyAdapter.cpp \
    WildTurkey.cpp

HEADERS += \
    Duck.hpp \
    MallardDuck.hpp \
    Turkey.hpp \
    TurkeyAdapter.hpp \
    WildTurkey.hpp
