QT       += core gui
TEMPLATE = app
TARGET = qtjob

LIBS += -L"C:/lib/QxOrm/lib" -lQxOrmd
QT += sql
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/corp.cpp \
    data/daocorp.cpp \
    jfind.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    adao.h \
    data/corp.h \
    data/daocorp.h \
    jfind.h \
    mainwindow.h \
    precompiled.h

FORMS += \
    mainwindow.ui
CONFIG += precompile_headers
PRECOMPILED_HEADER = precompiled.h
INCLUDEPATH += "C:/lib/QxOrm/include"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

