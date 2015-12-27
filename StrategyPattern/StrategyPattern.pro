TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    robot.cpp

HEADERS += \
    aggressivebehavioral.h \
    defensivebehavioral.h \
    ibehavioral.h \
    ifire.h \
    missilefire.h \
    normalbehavioral.h \
    normalfire.h \
    robot.h
