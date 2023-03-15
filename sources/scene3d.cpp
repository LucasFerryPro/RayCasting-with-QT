#include <../headers/scene3d.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>
#include <QRectF>

Scene3D::Scene3D() : QGraphicsScene()
{
    this->setBackgroundBrush(QBrush(QColor(0, 255, 0)));
};

void Scene3D::render3D(std::vector<Raycast> rays){
    this->clear();

    for (Raycast ray : rays){
        double rayL = (8*320)/ray.getRaycastLength(); if(rayL > 320) rayL = 320; // 320 is the height of the window (in pixels)
        double rayN = ray.getRaycastNumber();
        QRectF rect(
            rayN*8,
            -rayL*2,
            8,
            rayL*4
            );
        addRect(rect,QPen(Qt::black),QBrush(Qt::black));
    }
}