TEMPLATE = app
QT += quick


CONFIG += c++17
SOURCES += main.cpp
RESOURCES += qml.qrc

QML_IMPORT_PATH += $$top_builddir/plugins/


android: {
    ANDROID_EXTRA_LIBS += $$top_builddir/plugins/MyWonderfulPlugin/libplugins_MyWonderfulPlugin_MyWonderfulPlugin_arm64-v8a.so
}
