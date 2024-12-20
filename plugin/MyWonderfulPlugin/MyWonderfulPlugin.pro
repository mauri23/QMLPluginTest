QT += quick
CONFIG += plugin qmltypes
TEMPLATE = lib

QML_IMPORT_NAME = MyWonderfulPlugin
QML_IMPORT_MAJOR_VERSION = 1
DESTDIR = $$top_builddir/plugins/$$QML_IMPORT_NAME
TARGET = $$qt5LibraryTarget($$QML_IMPORT_NAME, "plugins/$$QML_IMPORT_NAME/")

uri = MyWonderfulPlugin

SOURCES += MyWonderfulPlugin.cpp
HEADERS +=


android:{
    ANDROID_EXTRA_PLUGINS += $$top_builddir/plugins/MyWonderfulPlugin
}

RESOURCES += \
    qml.qrc
