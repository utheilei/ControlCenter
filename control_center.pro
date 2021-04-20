QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = control_center
TEMPLATE = app
#CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

CONFIG += debug_and_release  c++11 link_pkgconfig
CONFIG (debug, debug|release) {
    TARGET = control_center
} else {
    TARGET = control_center
}

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
    widgets/displaytime.cpp \
    widgets/iconwidget.cpp \
    iconthemewidget.cpp \
    ArrowCircleButton.cpp \
    widgets/commonstylewidget.cpp \
    widgets/SettingWidget.cpp \
    widgets/StyleButton.cpp \
    widgets/cscrolltext.cpp \
    widgets/CircleItemCheckButton.cpp \
    widgets/waterprogressbar.cpp \
    widgets/gaugespeed.cpp \
    modules/displaywidget.cpp \
    HoverDelegate.cpp \
    modules/defappwidget.cpp \
    modules/networkwidget.cpp \
    widgets/treeitem.cpp \
    widgets/treemodel.cpp \
    widgets/TreeView.cpp \
    widgets/treeviewdelegate.cpp \
    modules/soundwidget.cpp

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
    widgets/displaytime.h \
    widgets/iconwidget.h \
    iconthemewidget.h \
    ArrowCircleButton.h \
    widgets/commonstylewidget.h \
    widgets/SettingWidget.h \
    widgets/StyleButton.h \
    widgets/cscrolltext.h \
    widgets/CircleItemCheckButton.h \
    widgets/waterprogressbar.h \
    widgets/gaugespeed.h \
    modules/displaywidget.h \
    HoverDelegate.h \
    modules/defappwidget.h \
    modules/networkwidget.h \
    widgets/treeitem.h \
    widgets/treemodel.h \
    widgets/TreeView.h \
    widgets/treeviewdelegate.h \
    modules/soundwidget.h

TRANSLATIONS = control_center_zh_CN.ts

DISTFILES +=

translation.path    = /usr/share/control_center/translations
translation.files   = translations/*.qm

executable.path    = /usr/bin
executable.files   = control_center

lib.path    = /usr/lib
lib.files   = lib/*

application.path    = /usr/share/applications
application.files   = application/control_center.desktop

icon.path    = /usr/share/icons
icon.files   = application/*.svg

INSTALLS       += translation executable lib application icon
