#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T10:11:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ObjectLocalizer
TEMPLATE = app

INCLUDEPATH += C:\\opencv2.4.8\\opencv\\build\\include
INCLUDEPATH += C:\\MQTT\\inc

SOURCES += main.cpp\
        olmainwindow.cpp \
    imagesnapperproxy.cpp \
    positiont.cpp \
    mqttnode.cpp \
    objectpickerproxy.cpp \
    sceneimage.cpp \
    featureimage.cpp \
    detector.cpp

HEADERS  += olmainwindow.h \
    imagesnapperproxy.h \
    positiont.h \
    mqttnode.h \
    objectpickerproxy.h \
    sceneimage.h \
    featureimage.h \
    detector.h \
    convertcvmat.h

LIBS += -LC:\\opencv2.4.8\\mybuild\\lib \
        libopencv_core248d \
        libopencv_highgui248d \
        -LC:\\MQTT\\lib \
        libpaho-mqtt3c.dll \

FORMS    += olmainwindow.ui

RESOURCES += \
    olmainwindow.qrc

