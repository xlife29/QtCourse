QT += widgets
CONFIG += c++11
TARGET = SimpleTextEditor_Designer
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp codeeditor.cpp replacedialog.cpp finddialog.cpp aboutdialog.cpp
HEADERS += mainwindow.h codeeditor.h replacedialog.h finddialog.h aboutdialog.h
FORMS += mainwindow.ui replacedialog.ui finddialog.ui aboutdialog.ui
