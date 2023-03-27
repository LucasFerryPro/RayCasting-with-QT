#include <../headers/scene3d.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>
#include <QRectF>

Scene3D::Scene3D() : QGraphicsScene()
{
    this->setBackgroundBrush(QBrush(Qt::white));
};

void Scene3D::render3D(std::vector<Raycast> rays){
    this->clear();

    QRectF rect(0,-1,800,-400);
    addRect(rect,QPen(Qt::blue),QBrush(Qt::blue));

    QRectF rect2(0,0,800,400);
    addRect(rect2,QPen(Qt::green),QBrush(Qt::green));

    for (Raycast ray : rays){
        double rayL = (8*320)/ray.getRaycastLength(); if(rayL > 320) rayL = 320; // 320 is the height of the window (in pixels)
        double rayN = ray.getRaycastNumber();
        QRectF rect(
            rayN*800/rays.size(),
            -rayL*2,
            800/rays.size(),
            rayL*4
            );
        addRect(rect,QPen(Qt::darkGray),QBrush(Qt::darkGray));
    }
}