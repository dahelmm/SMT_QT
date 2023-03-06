QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DEFINES += DEBUGGING_OUTPUT

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Connection/Transceiver/transmitter.cpp \
    Connection/Transceiver/Udp/udp.cpp \
    Elcus/MainElcusDocs/OpenPCI4bySN.cpp \
    Elcus/configuringnewconnectionwithelcus.cpp \
    Elcus/connectnewelcus.cpp \
    Elcus/disconnectfromelcus.cpp \
    Elcus/elcushelper.cpp \
    Connection/connection.cpp \
    looptimer.cpp \
    main.cpp \
    mainwindow.cpp \
    senderlog2files.cpp \
    stylehelper.cpp

HEADERS += \
    Connection/Transceiver/transmitter.h \
    Connection/Transceiver/Udp/udp.h \
    Elcus/MainElcusDocs/ArincPCI_4.h \
    Elcus/MainElcusDocs/intrfacePCI4.h \
    Elcus/MainElcusDocs/ioctlPCI4.h \
    Elcus/configuringnewconnectionwithelcus.h \
    Elcus/connectnewelcus.h \
    Elcus/disconnectfromelcus.h \
    Elcus/elcushelper.h \
    Connection/connection.h \
    looptimer.h \
    mainwindow.h \
    senderlog2files.h \
    stylehelper.h

FORMS += \
    Elcus/configuringnewconnectionwithelcus.ui \
    Elcus/connectnewelcus.ui \
    Elcus/disconnectfromelcus.ui \
    mainwindow.ui \
    senderlog2files.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc

win32 {

LIBS += -lsetupapi

}
