#-------------------------------------------------
#
# Project created by QtCreator 2016-10-05T10:04:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EDPreviewMotor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    motor.cpp

HEADERS  += mainwindow.h \
            motor.h \
            wiringPi.h

FORMS    += mainwindow.ui \

#LIBS     += -lwiringPi
