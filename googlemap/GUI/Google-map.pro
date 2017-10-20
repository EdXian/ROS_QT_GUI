

QT       += core gui webengine webenginewidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Google-map
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        geocode_data_manager.cpp
HEADERS  += mainwindow.h\
            geocode_data_manager.cpp
FORMS    += mainwindow.ui

#DISTFILES +=

RESOURCES += \
    resources.qrc
