#ifndef SCENE2D_H
#define SCENE2D_H

#include <QGraphicsScene>
#include <../headers/raycast.hpp>
#include <../headers/define.hpp>

class Scene2D : public QGraphicsScene{
    private:

    public:
    Scene2D(QObject *parent = nullptr);
    void draw(int map[WORLD_SIZE][WORLD_SIZE]);
};
#endif