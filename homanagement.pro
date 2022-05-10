#-------------------------------------------------
#
# Project created by QtCreator 2021-01-14T13:03:09
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homanagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    didoctor.cpp \
    dioffice.cpp \
    dipatient.cpp \
    diward.cpp \
    dddoctor.cpp \
    ddoffice.cpp \
    ddward.cpp \
    ddpatient.cpp \
    dmdoctor.cpp \
    dmoffice.cpp \
    dmpatient.cpp \
    dmward.cpp \
    dqdoctor.cpp \
    dqoffice.cpp \
    dqpatient.cpp \
    dqward.cpp

HEADERS += \
        mainwindow.h \
    didoctor.h \
    dioffice.h \
    dipatient.h \
    diward.h \
    dddoctor.h \
    ddoffice.h \
    ddward.h \
    ddpatient.h \
    dmdoctor.h \
    dmoffice.h \
    dmpatient.h \
    dmward.h \
    dqdoctor.h \
    dqoffice.h \
    dqpatient.h \
    dqward.h

FORMS += \
        mainwindow.ui \
    didoctor.ui \
    dioffice.ui \
    dipatient.ui \
    diward.ui \
    dddoctor.ui \
    ddoffice.ui \
    ddward.ui \
    ddpatient.ui \
    dmdoctor.ui \
    dmoffice.ui \
    dmpatient.ui \
    dmward.ui \
    dqdoctor.ui \
    dqoffice.ui \
    dqpatient.ui \
    dqward.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
