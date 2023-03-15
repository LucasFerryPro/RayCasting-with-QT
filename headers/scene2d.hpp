#ifndef SCENE2D_H
#define SCENE2D_H

#include <QGraphicsScene>
#include <../headers/raycast.hpp>
#include <../headers/define.hpp>
#include <../headers/player.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/scene3d.hpp>

class Scene2D : public QGraphicsScene{
    private:
    int map[WORLD_SIZE][WORLD_SIZE];
    RaycastEngine re;
    Player player;
    Scene3D *scene3d;

    public:
    Scene2D(int map[WORLD_SIZE][WORLD_SIZE],Player player, RaycastEngine re, Scene3D *scene3d);
    void draw();
    bool checkCollision(int direction);
    int posXToCaseX(double x);
    int posYToCaseY(double y);
    void setMap(int map[WORLD_SIZE][WORLD_SIZE]);
    void setRaycastEngine(RaycastEngine re);
    void setPlayer(Player player);


    protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif