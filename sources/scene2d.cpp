#include <../headers/scene2d.hpp>
#include <QPainter>
#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>
#include <../headers/case.hpp>

#include <QKeyEvent>

Player p = Player(200,150);

Scene2D::Scene2D(QObject *parent, int map[WORLD_SIZE][WORLD_SIZE]) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 400, 400);
    this->setBackgroundBrush(QBrush(QColor(192, 192, 192)));
    this->setMap(map);
}

void Scene2D::draw(){

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
    addEllipse(p,blackPen,playerBrush);

    // Draw Raycasts
    RaycastEngine r = RaycastEngine(p, 100);
    r.emitRay();   

    for (Raycast ray : r.getRays()){
        addLine(ray,raycastPen);
    }
}

void Scene2D::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Z:
            if(checkCollision(1)){
                p.setPlayerPos(p.getPlayerX() + p.getPlayerSpeed() * cos(RADIAN(p.getPlayerA())), p.getPlayerY() + p.getPlayerSpeed() * sin(RADIAN(p.getPlayerA())));
            }else{
                printf("cant move   ");
            }
            break;
        case Qt::Key_S:
            if(checkCollision(2)){
                p.setPlayerPos(p.getPlayerX() - p.getPlayerSpeed() * cos(RADIAN(p.getPlayerA())), p.getPlayerY() - p.getPlayerSpeed() * sin(RADIAN(p.getPlayerA())));
            }else{
                printf("cant move   ");
            }
            break;
        case Qt::Key_Q:
            p.setPlayerAngle(p.getPlayerA() - p.getPlayerTurnSpeed());
            break;
        case Qt::Key_D:
            p.setPlayerAngle(p.getPlayerA() + p.getPlayerTurnSpeed());
            break;
    }
    printf("Player X : %f, Player Y : %f Player A : %f \n",p.getPlayerX(),p.getPlayerY(),p.getPlayerA());
    this->clear();
    this->draw();
}

int Scene2D::posXToCaseX(double x){
    return floor((int(x) % WHEIGHT)/50);
}

int Scene2D::posYToCaseY(double y){
    return floor((int(y) % WHEIGHT)/50);
}

bool Scene2D::checkCollision(int direction){

    int caseX1;
    int caseY1;
    int caseX2;
    int caseY2;

    switch (direction){
    case 1: //forward
        caseX1 = posXToCaseX(
            p.getPlayerX() + (p.getPlayerSpeed()) * cos(RADIAN(p.getPlayerA()))+5
        );
        caseY1 = posYToCaseY(
            p.getPlayerY() + (p.getPlayerSpeed()) * sin(RADIAN(p.getPlayerA()))+5
        );
        caseX2 = posXToCaseX(
            p.getPlayerX() + (p.getPlayerSpeed()) * cos(RADIAN(p.getPlayerA()))-5
        );
        caseY2 = posYToCaseY(
            p.getPlayerY() + (p.getPlayerSpeed()) * sin(RADIAN(p.getPlayerA()))-5
        );
        break;
    case 2: //backward
        caseX1 = posXToCaseX(
            p.getPlayerX() - (p.getPlayerSpeed()) * cos(RADIAN(p.getPlayerA()))+5
        );
        caseY1 = posYToCaseY(
            p.getPlayerY() - (p.getPlayerSpeed()) * sin(RADIAN(p.getPlayerA()))+5
        );
        caseX2 = posXToCaseX(
            p.getPlayerX() - (p.getPlayerSpeed()) * cos(RADIAN(p.getPlayerA()))-5
        );
        caseY2 = posYToCaseY(
            p.getPlayerY() - (p.getPlayerSpeed()) * sin(RADIAN(p.getPlayerA()))-5
        );
    }

    return (map[caseY1][caseX1] == 0 && map[caseY2][caseX2] == 0);
}



void Scene2D::setMap(int map[WORLD_SIZE][WORLD_SIZE]){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            this->map[i][j] = map[i][j];
        }
    }
}