#include <../headers/scene2d.hpp>

Scene2D::Scene2D(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 400, 400);
    this->setBackgroundBrush(QBrush(QColor(255, 0, 0)));
}