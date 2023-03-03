QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Elcus/MainElcusDocs/OpenPCI4bySN.cpp \
    Elcus/configuringnewconnectionwithelcus.cpp \
    Elcus/connectnewelcus.cpp \
    Elcus/disconnectfromelcus.cpp \
    Elcus/elcushelper.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Elcus/MainElcusDocs/ArincPCI_4.h \
    Elcus/MainElcusDocs/intrfacePCI4.h \
    Elcus/MainElcusDocs/ioctlPCI4.h \
    Elcus/configuringnewconnectionwithelcus.h \
    Elcus/connectnewelcus.h \
    Elcus/disconnectfromelcus.h \
    Elcus/elcushelper.h \
    mainwindow.h

FORMS += \
    Elcus/configuringnewconnectionwithelcus.ui \
    Elcus/connectnewelcus.ui \
    Elcus/disconnectfromelcus.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc

win32 {

LIBS += -lsetupapi

}
