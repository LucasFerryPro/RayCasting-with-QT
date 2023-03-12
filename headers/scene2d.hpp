#ifndef SCENE2D_H
#define SCENE2D_H

#include <QGraphicsScene>
#include <../headers/raycast.hpp>
#include <../headers/define.hpp>

class Scene2D : public QGraphicsScene{
    private:
    int map[WORLD_SIZE][WORLD_SIZE];

    public:
    Scene2D(QObject *parent,int map[WORLD_SIZE][WORLD_SIZE]);
    void draw();
    bool checkCollision(int direction);
    int posXToCaseX(double x);
    int posYToCaseY(double y);
    void setMap(int map[WORLD_SIZE][WORLD_SIZE]);


    protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif