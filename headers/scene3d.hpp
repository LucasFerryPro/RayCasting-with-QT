#ifndef SCENE3D_H
#define SCENE3D_H

#include <QGraphicsScene>
#include <../headers/raycast_engine.hpp>

class Scene3D : public QGraphicsScene{
    private:

    public:
    Scene3D();
    void render3D(std::vector<Raycast> rays);

};
#endif