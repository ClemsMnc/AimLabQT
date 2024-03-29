QT += core gui widgets multimedia

TARGET = AimLabApp
TEMPLATE = app

HEADERS += GameWindow.h \
           ConfigDialog.h

SOURCES += main.cpp \
           GameWindow.cpp \
           ConfigDialog.cpp

FORMS += GameWindow.ui

RESOURCES += resources.qrc
