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
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 3 * 100); // 3 vertices per triangle
        geometry->setDrawingMode(QSGGeometry::DrawTriangles);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        material->setColor(QColor(0, 255, 0));
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
    }

    QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
    int count = geometry->vertexCount() / 3; // 3 vertices per triangle
    float radius = qMin(width(), height()) / 2;
    float centerX = width() / 2;
    float centerY = height() / 2;

    for (int i = 0; i < count; ++i) {
        float angle1 = i * 2 * M_PI / count;
        float angle2 = (i + 1) * 2 * M_PI / count;
        vertices[3 * i].set(centerX, centerY);
        vertices[3 * i + 1].set(centerX + radius * cos(angle1), centerY + radius * sin(angle1));
        vertices[3 * i + 2].set(centerX + radius * cos(angle2), centerY + radius * sin(angle2));
    }

    node->markDirty(QSGNode::DirtyGeometry);
    return node;
}
