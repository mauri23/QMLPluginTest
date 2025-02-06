#ifndef MYWONDERFULCOMPONENT_H
#define MYWONDERFULCOMPONENT_H


#include <QQuickItem>
#include <QSGGeometryNode>


class MyWonderfulComponent : public QQuickItem {
    Q_OBJECT
public:
    MyWonderfulComponent();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;
};
#endif // MYWONDERFULCOMPONENT_H
