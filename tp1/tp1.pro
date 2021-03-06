#-------------------------------------------------
#
# Project created by QtCreator 2014-09-14T13:21:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tp1
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Graphics/GrayscaleImage.cpp \
    Graphics/GrayscaleImageInfo.cpp \
    Graphics/GrayscaleHistogram.cpp \
    Graphics/GrayscaleImageFactory.cpp \
    Graphics/MatchingFunction.cpp \
    Graphics/GrayscaleCumulativeHistogram.cpp \
    Graphics/NegatingMatchingFunction.cpp \
    Graphics/CroppingMatchingFunction.cpp \
    Graphics/GrayscaleConstantHistogram.cpp \
    Graphics/GrayscaleLinearHistogram.cpp \
    Graphics/GrayscaleSquaredRootHistogram.cpp

HEADERS  += MainWindow.h \
    Graphics/GrayscaleImage.h \
    Graphics/GrayscaleImageInfo.h \
    Graphics/GrayscaleHistogram.h \
    Graphics/GrayscaleImageFactory.h \
    Graphics/MatchingFunction.h \
    Graphics/GrayscaleCumulativeHistogram.h \
    Graphics/NegatingMatchingFunction.h \
    Graphics/CroppingMatchingFunction.h \
    Graphics/GrayscaleConstantHistogram.h \
    Graphics/Graphics.h \
    Graphics/GrayscaleLinearHistogram.h \
    Graphics/GrayscaleSquaredRootHistogram.h

FORMS    += MainWindow.ui
