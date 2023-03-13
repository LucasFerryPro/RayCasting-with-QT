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
    QBrush greenBrush (QColor(44,255,44));
    QBrush blueBrush (QColor(44,44,255));

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

    // Draw test Collisions
    /*
    double angle1 = p.getPlayerA()+45;
    double angle2 = p.getPlayerA()-45;
    double angle3 = p.getPlayerA()+90;
    double angle4 = p.getPlayerA()-90;

    QRectF r1(
        (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle1)))-2.5,
        (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle1)))-2.5,
        5,5);
    QRectF r2(
        (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle2)))-2.5,
        (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle2)))-2.5,
        5,5);
    QRectF r3(
        (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(angle1)))-2.5,
        (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(angle1)))-2.5,
        5,5);
    QRectF r4(
        (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(angle2)))-2.5,
        (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(angle2)))-2.5,
        5,5);
    QRectF r5(
        (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(p.getPlayerA())))-2.5,
        (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(p.getPlayerA())))-2.5,
        5,5);

    QRectF r6(
        (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(p.getPlayerA())))-2.5,
        (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(p.getPlayerA())))-2.5,
        5,5);  
    QRectF r7(
        (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle3)))-2.5,
        (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle3)))-2.5,
        5,5);
    QRectF r8(
        (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle4)))-2.5,
        (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle4)))-2.5,
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
    
}

void Scene2D::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Z:
            if(checkCollision(1)){
                p.setPlayerPos(p.getPlayerX() + p.getPlayerSpeed() * cos(RADIAN(p.getPlayerA())), p.getPlayerY() + p.getPlayerSpeed() * sin(RADIAN(p.getPlayerA())));
            }else{
                printf("cant move   ");
                printf("%i\n",map[2][1]);
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
    printf("\nX: %i",int(floor((int(x) % WHEIGHT)/50)));
    return floor((int(x) % WHEIGHT)/50);
}

int Scene2D::posYToCaseY(double y){
    printf("\nY: %i\n",int(floor((int(y) % WHEIGHT)/50)));
    return floor((int(y) % WHEIGHT)/50);
}

bool Scene2D::checkCollision(int direction){

    int caseX1,caseY1,caseX2,caseY2,caseX3,caseY3,caseX4,caseY4,caseX5,caseY5;

    double angle1 = p.getPlayerA()+45;
    double angle2 = p.getPlayerA()-45;
    double angle3 = p.getPlayerA()+90;
    double angle4 = p.getPlayerA()-90;

    switch (direction){
    case 1: //forward
        caseX1 = posXToCaseX(
            (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle1)))
        );
        caseY1 = posYToCaseY(
            (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle1)))
        );
        caseX2 = posXToCaseX(
            (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle2)))
        );
        caseY2 = posYToCaseY(
            (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle2)))
        );
        caseX3 = posXToCaseX(
            (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(p.getPlayerA())))
        );
        caseY3 = posYToCaseY(
            (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(p.getPlayerA())))
        );
        caseX4 = posXToCaseX(
            (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle3)))
        );
        caseY4 = posYToCaseY(
            (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle3)))
        );
        caseX5 = posXToCaseX(
            (p.getPlayerX() + (p.getPlayerSpeed()+3) * cos(RADIAN(angle4)))
        );
        caseY5 = posYToCaseY(
            (p.getPlayerY() + (p.getPlayerSpeed()+3) * sin(RADIAN(angle4)))
        );
        break;
    case 2: //backward
        caseX1 = posXToCaseX(
            (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(angle1)))
        );
        caseY1 = posYToCaseY(
            (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(angle1)))
        );
        caseX2 = posXToCaseX(
            (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(angle2)))
        );
        caseY2 = posYToCaseY(
            (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(angle2)))
        );
        caseX3 = posXToCaseX(
            (p.getPlayerX() - (p.getPlayerSpeed()+5) * cos(RADIAN(p.getPlayerA())))
        );
        caseY3 = posYToCaseY(
            (p.getPlayerY() - (p.getPlayerSpeed()+5) * sin(RADIAN(p.getPlayerA())))
        );
        caseX4 = posXToCaseX(
            (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(angle3)))
        );
        caseY4 = posYToCaseY(
            (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(angle3)))
        );
        caseX5 = posXToCaseX(
            (p.getPlayerX() - (p.getPlayerSpeed()+3) * cos(RADIAN(angle4)))
        );
        caseY5 = posYToCaseY(
            (p.getPlayerY() - (p.getPlayerSpeed()+3) * sin(RADIAN(angle4)))
        );
    }

    printf("%i\n",caseX3);
    printf("%i\n",caseY3);

    return (map[caseY1][caseX1] == 0 && map[caseY2][caseX2] == 0 && map[caseY3][caseX3] == 0);
}



void Scene2D::setMap(int map[WORLD_SIZE][WORLD_SIZE]){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            this->map[i][j] = map[i][j];
        }
    }
}