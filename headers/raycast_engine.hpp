#ifndef RAYCASTENGINE_H
#define RAYCASTENGINE_H

#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
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
    void emitRay();
    std::vector<Raycast> getRays();
};
#endif