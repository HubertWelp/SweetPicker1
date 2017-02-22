TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += C:\\opencv2.4.8\\opencv\\build\\include
LIBS += -LC:\\opencv2.4.8\\mybuild\\lib \
        libopencv_core248d \
        libopencv_highgui248d \
        libopencv_imgproc248d\

SOURCES += main.cpp

