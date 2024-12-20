#include <QQmlEngine>
#include <QQmlExtensionPlugin>

class MyWonderfulPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override {
        qmlRegisterType(QUrl("qrc:/MyWonderfulItem.qml"), uri, 1, 0, "MyWonderfulItem");
    }
};


#include "MyWonderfulPlugin.moc"
