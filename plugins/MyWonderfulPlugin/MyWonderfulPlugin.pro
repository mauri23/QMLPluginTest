QT += quick
CONFIG += plugin qmltypes
TEMPLATE = lib

QML_IMPORT_NAME = MyWonderfulPlugin
QML_IMPORT_MAJOR_VERSION = 1

android: {
    DESTDIR = $$top_builddir/plugins/$$QML_IMPORT_NAME
    TARGET = $$qt5LibraryTarget($$QML_IMPORT_NAME, "plugins/$$QML_IMPORT_NAME/")
}

win32: {
    CONFIG(debug, debug|release):DESTDIR = $$top_builddir/app/debug/$$QML_IMPORT_NAME
    CONFIG(release, debug|release):DESTDIR = $$top_builddir/app/release/$$QML_IMPORT_NAME
    TARGET = $$QML_IMPORT_NAME
}




uri = MyWonderfulPlugin

SOURCES += MyWonderfulPlugin.cpp
HEADERS +=


win32: {
    !equals(_PRO_FILE_PWD_, $$DESTDIR) {
        copy_qmldir.target = $$DESTDIR/qmldir
        copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
        copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
        QMAKE_EXTRA_TARGETS += copy_qmldir
        PRE_TARGETDEPS += $$copy_qmldir.target
    }
}

RESOURCES += \
    qml.qrc

DISTFILES += \
    qmldir
