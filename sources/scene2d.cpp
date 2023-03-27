#include <../headers/scene2d.hpp>
#include <QPainter>
#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>
#include <../headers/case.hpp>
#include <../headers/scene3d.hpp>

#include <QKeyEvent>

Scene2D::Scene2D(int map[WORLD_SIZE][WORLD_SIZE],Player player, RaycastEngine re, Scene3D *scene3d) : QGraphicsScene()
{
    this->setBackgroundBrush(QBrush(QColor(192, 192, 192)));
    this->setMap(map);
    this->setPlayer(player);
    this->setRaycastEngine(re);
    this->scene3d = scene3d;
}

void Scene2D::setRaycastEngine(RaycastEngine re){
    this->re = re;
}

void Scene2D::setPlayer(Player player){
    this->player=player;
}

void Scene2D::draw(){

    //Pens / Brushs
    QPen blackPen(Qt::black);
    QBrush blackBrush(Qt::black);
    QPen grayPen(QColor(212,212,212));
    QBrush grayBrush(QColor(212,212,212));
    QPen raycastPen (QColor(232, 158, 73));
    QBrush playerBrush (QColor(255,44,44));
    QBrush greenBrush (QColor(44,255,44));
    QBrush blueBrush (QColor(44,44,255));

    // Draw Cases
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            if(map[j][i] == 1){
                Case wall(i*CASE,j*CASE,1);
                addRect(wall,blackPen,blackBrush);
            }else if (map[j][i] == 0){
                Case wall(i*CASE,j*CASE,0);
                addRect(wall,grayPen,grayBrush);
            }
        }
    }

    // Draw Player
    addEllipse(player,blackPen,playerBrush);

    // Draw Raycasts
    re.emitRay(map); 
    for (Raycast ray : re.getRays()){
        addLine(ray,raycastPen);
    }

    // Draw test Collisions
    /*
    double angle1 = player.getPlayerA()+45;
    double angle2 = player.getPlayerA()-45;
    double angle3 = player.getPlayerA()+90;
    double angle4 = player.getPlayerA()-90;

    QRectF r1(
        (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle1)))-2.5,
        (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle1)))-2.5,
        5,5);
    QRectF r2(
        (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle2)))-2.5,
        (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle2)))-2.5,
        5,5);
    QRectF r3(
        (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(angle1)))-2.5,
        (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(angle1)))-2.5,
        5,5);
    QRectF r4(
        (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(angle2)))-2.5,
        (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(angle2)))-2.5,
        5,5);
    QRectF r5(
        (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(player.getPlayerA())))-2.5,
        (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(player.getPlayerA())))-2.5,
        5,5);

    QRectF r6(
        (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(player.getPlayerA())))-2.5,
        (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(player.getPlayerA())))-2.5,
        5,5);  
    QRectF r7(
        (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle3)))-2.5,
        (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle3)))-2.5,
        5,5);
    QRectF r8(
        (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle4)))-2.5,
        (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle4)))-2.5,
        5,5);

    addEllipse(r1,blackPen,blueBrush);
    addEllipse(r2,blackPen,blueBrush);
    addEllipse(r3,blackPen,blueBrush);
    addEllipse(r4,blackPen,blueBrush);
    addEllipse(r5,blackPen,blueBrush);
    addEllipse(r6,blackPen,blueBrush);
    addEllipse(r7,blackPen,blueBrush);
    addEllipse(r8,blackPen,blueBrush);
    */

   scene3d->render3D(re.getRays());
    
}

void Scene2D::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Z:
            if(checkCollision(1)){
                player.setPlayerPos(player.getPlayerX() + player.getPlayerSpeed() * cos(RADIAN(player.getPlayerA())), player.getPlayerY() + player.getPlayerSpeed() * sin(RADIAN(player.getPlayerA())));
            }else{
                printf("cant move   ");
                printf("%i\n",map[2][1]);
            }
            break;
        case Qt::Key_S:
            if(checkCollision(2)){
                player.setPlayerPos(player.getPlayerX() - player.getPlayerSpeed() * cos(RADIAN(player.getPlayerA())), player.getPlayerY() - player.getPlayerSpeed() * sin(RADIAN(player.getPlayerA())));
            }else{
                printf("cant move   ");
            }
            break;
        case Qt::Key_Q:
            player.setPlayerAngle(player.getPlayerA() - player.getPlayerTurnSpeed());
            break;
        case Qt::Key_D:
            player.setPlayerAngle(player.getPlayerA() + player.getPlayerTurnSpeed());
            break;
    }

    re.setPlayer(player);

    this->clear();
    this->draw();
}

int Scene2D::posXToCaseX(double x){
    return floor((int(x) % WHEIGHT)/25);
}

int Scene2D::posYToCaseY(double y){
    return floor((int(y) % WHEIGHT)/25);
}

bool Scene2D::checkCollision(int direction){

    int caseX1,caseY1,caseX2,caseY2,caseX3,caseY3,caseX4,caseY4,caseX5,caseY5;

    double angle1 = player.getPlayerA()+45;
    double angle2 = player.getPlayerA()-45;
    double angle3 = player.getPlayerA()+90;
    double angle4 = player.getPlayerA()-90;

    switch (direction){
    case 1: //forward
        caseX1 = posXToCaseX(
            (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle1)))
        );
        caseY1 = posYToCaseY(
            (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle1)))
        );
        caseX2 = posXToCaseX(
            (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle2)))
        );
        caseY2 = posYToCaseY(
            (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle2)))
        );
        caseX3 = posXToCaseX(
            (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(player.getPlayerA())))
        );
        caseY3 = posYToCaseY(
            (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(player.getPlayerA())))
        );
        caseX4 = posXToCaseX(
            (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle3)))
        );
        caseY4 = posYToCaseY(
            (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle3)))
        );
        caseX5 = posXToCaseX(
            (player.getPlayerX() + (player.getPlayerSpeed()+3) * cos(RADIAN(angle4)))
        );
        caseY5 = posYToCaseY(
            (player.getPlayerY() + (player.getPlayerSpeed()+3) * sin(RADIAN(angle4)))
        );
        break;
    case 2: //backward
        caseX1 = posXToCaseX(
            (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(angle1)))
        );
        caseY1 = posYToCaseY(
            (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(angle1)))
        );
        caseX2 = posXToCaseX(
            (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(angle2)))
        );
        caseY2 = posYToCaseY(
            (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(angle2)))
        );
        caseX3 = posXToCaseX(
            (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(player.getPlayerA())))
        );
        caseY3 = posYToCaseY(
            (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(player.getPlayerA())))
        );
        caseX4 = posXToCaseX(
            (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(angle3)))
        );
        caseY4 = posYToCaseY(
            (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(angle3)))
        );
        caseX5 = posXToCaseX(
            (player.getPlayerX() - (player.getPlayerSpeed()+3) * cos(RADIAN(angle4)))
        );
        caseY5 = posYToCaseY(
            (player.getPlayerY() - (player.getPlayerSpeed()+3) * sin(RADIAN(angle4)))
        );
    }
    return (map[caseY1][caseX1] == 0 && map[caseY2][caseX2] == 0 && map[caseY3][caseX3] == 0);
}



void Scene2D::setMap(int map[WORLD_SIZE][WORLD_SIZE]){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            this->map[i][j] = map[i][j];
        }
    }
}