#include "MyWonderfulComponent.h"
#include <QSGGeometry>
#include <QSGFlatColorMaterial>
#include <QOpenGLFunctions>

MyWonderfulComponent::MyWonderfulComponent() {
    setFlag(ItemHasContents, true);
}

QSGNode *MyWonderfulComponent::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) {
    QSGGeometryNode *node = nullptr;
    QSGGeometry *geometry = nullptr;

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 100);
        geometry->setDrawingMode(GL_TRIANGLE_FAN);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        material->setColor(QColor(255, 0, 0));
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
    }

    QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
    int count = geometry->vertexCount();
    float radius = qMin(width(), height()) / 2;
    float centerX = width() / 2;
    float centerY = height() / 2;

    vertices[0].set(centerX, centerY);
    for (int i = 1; i < count; ++i) {
        float angle = (i - 1) * 2 * M_PI / (count - 1);
        vertices[i].set(centerX + radius * cos(angle), centerY + radius * sin(angle));
    }

    node->markDirty(QSGNode::DirtyGeometry);
    return node;
}
