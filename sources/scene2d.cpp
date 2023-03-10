#include <../headers/scene2d.hpp>
#include <QPainter>
#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>
#include <../headers/case.hpp>

Scene2D::Scene2D(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 400, 400);
    this->setBackgroundBrush(QBrush(QColor(192, 192, 192)));
}

void Scene2D::draw(int map[WORLD_SIZE][WORLD_SIZE] ){

    //Pens / Brushs
    QPen blackPen(Qt::black);
    QBrush blackBrush(Qt::black);
    QPen grayPen(QColor(212,212,212));
    QBrush grayBrush(QColor(212,212,212));
    QPen raycastPen (QColor(232, 158, 73));
    QBrush playerBrush (QColor(255,44,44));

    // Draw Cases
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            if(map[j][i] == 1){
                Case wall(i*CASE+LINE,j*CASE+LINE,1);
                addRect(wall,blackPen,blackBrush);
            }else if (map[j][i] == 0){
                Case wall(i*CASE+LINE,j*CASE+LINE,0);
                addRect(wall,grayPen,grayBrush);
            }
        }
    }

    // Draw Player
    Player p = Player(200,150);
    addEllipse(p,blackPen,playerBrush);

    // Draw Raycasts
    RaycastEngine r = RaycastEngine(p, 100);
    r.emitRay();   

    for (Raycast ray : r.getRays()){
        addLine(ray,raycastPen);
    }
}