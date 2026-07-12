QT += widgets

CONFIG += c++17

TARGET = Streetplanner

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcitydialog.cpp \
    addstreetdialog.cpp \
    city.cpp \
    dijkstra.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapio.cpp \
    mapiofileinput.cpp \
    mapionrw.cpp \
    street.cpp \
    abstractmap.cpp

HEADERS += \
    addcitydialog.h \
    addstreetdialog.h \
    city.h \
    dijkstra.h \
    mainwindow.h \
    map.h \
    mapio.h \
    mapiofileinput.h \
    mapionrw.h \
    street.h \
    abstractmap.h

FORMS += \
    addcitydialog.ui \
    addstreetdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
