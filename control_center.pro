QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = control_center
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    listwidget.cpp \
    accoutwidget.cpp \
    userwidget.cpp \
    newaccout.cpp \
    networkaccout.cpp \
    logonwidget.cpp \
    circlebutton.cpp \
    avatarwidget.cpp \
    avatardel.cpp \
    circleview.cpp \
    roundcolorwidget.cpp \
    roundcolorview.cpp \
    themepix.cpp \
    themewidget.cpp \
    personalizationwidget.cpp \
    commonwidget.cpp \
    settingsgroup.cpp \
    settingsitem.cpp \
    fullnameedit.cpp \
    listiconview.cpp \
    delegate.cpp \
    titleswidget.cpp \
    widgets/iwindow.cpp \
    widgets/clockwidget.cpp \
    datetimewidget.cpp \
    widgets/displaytime.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    listwidget.h \
    accoutwidget.h \
    userwidget.h \
    newaccout.h \
    networkaccout.h \
    logonwidget.h \
    circlebutton.h \
    avatarwidget.h \
    avatardel.h \
    circleview.h \
    roundcolorwidget.h \
    roundcolorview.h \
    themepix.h \
    themewidget.h \
    personalizationwidget.h \
    commonwidget.h \
    settingsgroup.h \
    settingsitem.h \
    fullnameedit.h \
    listiconview.h \
    delegate.h \
    titleswidget.h \
    widgets/iwindow.h \
    widgets/clockwidget.h \
    datetimewidget.h \
    widgets/displaytime.h

TRANSLATIONS = control_center_zh_CN.ts

DISTFILES +=
