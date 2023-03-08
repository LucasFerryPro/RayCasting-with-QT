#include <../headers/view3d.hpp>

View3D::View3D(QGraphicsScene *scene) : QGraphicsView(scene)
{
    this->setFixedSize(400, 400);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setDragMode(QGraphicsView::ScrollHandDrag);
};
