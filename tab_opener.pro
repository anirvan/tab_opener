#-------------------------------------------------
#
# Project created by QtCreator 2014-04-05T15:44:51
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(release, debug|release) {
    #This is a release build
    DEFINES += QT_NO_DEBUG_OUTPUT
} else {
    #This is a debug build
}

TARGET = tab_opener
TEMPLATE = app
INCLUDEPATH += include

SOURCES += \
    src/main.cpp \
    src/hoverbutton.cpp \
    src/filelist.cpp \
    src/cmdlist.cpp \
    src/mainwindow.cpp \
    src/datastore.cpp

HEADERS  += \
    include/hoverbutton.h \
    include/filelist.h \
    include/cmdlist.h \
    include/mainwindow.h \
    include/datastore.h

FORMS    += \
    ui/filelist.ui \
    ui/cmdlist.ui \
    ui/mainwindow.ui

RESOURCES += \
    images.qrc
