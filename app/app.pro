TEMPLATE = app
QT += quick


CONFIG += c++17
SOURCES += main.cpp
RESOURCES += qml.qrc

QML_IMPORT_PATH += $$top_builddir/plugins/


android: {
    ANDROID_EXTRA_PLUGINS += $$top_builddir/plugins/
}
