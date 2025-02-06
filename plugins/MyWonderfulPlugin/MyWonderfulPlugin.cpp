#include <QQmlEngine>
#include <QQmlExtensionPlugin>
#include "MyWonderfulComponent.h"

class MyWonderfulPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override {

        qDebug()<<"MyWonderfulPlugin::registerTypes";

        qmlRegisterType(QUrl("qrc:/MyWonderfulItem.qml"), uri, 1, 0, "MyWonderfulItem");

        qmlRegisterType<MyWonderfulComponent>(uri, 1, 0, "MyWonderfulComponent");
    }
};


#include "MyWonderfulPlugin.moc"
