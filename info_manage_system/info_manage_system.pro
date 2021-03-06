#-------------------------------------------------
#
# Project created by QtCreator 2019-04-02T20:03:23
#
#-------------------------------------------------

QT       += core gui sql axcontainer
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = info_manage_system
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
    excelengine.cpp \
    getcarduid.cpp \
        main.cpp \
        mainwindow.cpp \
    in_out_account_page.cpp \
    account_card_borrow_page.cpp \
    login_page.cpp \
    searchpage.cpp

HEADERS += \
    data_struct.h \
    excelengine.h \
    getcarduid.h \
        mainwindow.h \
    in_out_account_page.h \
    account_card_borrow_page.h \
    login_page.h \
    searchpage.h

FORMS += \
    getcarduid.ui \
        mainwindow.ui \
    in_out_account_page.ui \
    account_card_borrow_page.ui \
    login_page.ui \
    searchpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc
