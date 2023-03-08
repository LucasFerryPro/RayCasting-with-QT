#include <../headers/scene3d.hpp>

Scene3D::Scene3D(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(400, 0, 400, 400);
    this->setBackgroundBrush(QBrush(QColor(0, 255, 0)));
};