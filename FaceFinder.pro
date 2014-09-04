#-------------------------------------------------
#
# Project created by QtCreator 2014-09-04T15:29:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FaceFinder
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    VideoProcessor.hpp

FORMS    += mainwindow.ui

LIBS += /usr/local/lib/libopencv_calib3d.so \
/usr/local/lib/libopencv_nonfree.so \
/usr/local/lib/libopencv_contrib.so \
/usr/local/lib/libopencv_objdetect.so \
/usr/local/lib/libopencv_core.so \
/usr/local/lib/libopencv_ocl.so \
/usr/local/lib/libopencv_features2d.so \
/usr/local/lib/libopencv_photo.so \
/usr/local/lib/libopencv_flann.so \
/usr/local/lib/libopencv_stitching.so \
/usr/local/lib/libopencv_gpu.so \
/usr/local/lib/libopencv_superres.so \
/usr/local/lib/libopencv_highgui.so \
/usr/local/lib/libopencv_video.so \
/usr/local/lib/libopencv_imgproc.so \
/usr/local/lib/libopencv_videostab.so \
/usr/local/lib/libopencv_legacy.so
