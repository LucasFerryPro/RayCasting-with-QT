#ifndef RAYCASTENGINE_H
#define RAYCASTENGINE_H

#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
#include <../headers/define.hpp>
#include <vector>

class RaycastEngine 
{
private:
    Player player;
    int nb_rays;
    std::vector<Raycast> rays;

public:
    RaycastEngine(Player player, int nb_rays);
    ~RaycastEngine();
    void emitRay(int map[WORLD_SIZE][WORLD_SIZE]);
    std::vector<Raycast> getRays();
    int posXToCaseX(double x);
    int posYToCaseY(double y);
    QPointF getRaycastEnd(double angle, int map[WORLD_SIZE][WORLD_SIZE]);
};
#endif