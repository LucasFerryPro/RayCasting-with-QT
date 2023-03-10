#include <../headers/raycast_engine.hpp>
#include <../headers/raycast.hpp>

#define PI 3.14159265
#define RADIAN(x) (x * PI / 180)

RaycastEngine::RaycastEngine(Player player, int nb_rays){
    this->player = player;
    this->nb_rays = nb_rays;
    this->rays = std::vector<Raycast>(nb_rays);
}

RaycastEngine::~RaycastEngine(){
    this->rays.clear();
}

void RaycastEngine::emitRay(){
    this->rays.clear();
    for(int i = 0; i < this->nb_rays; i++){
        this->rays.insert (this->rays.begin(),Raycast(
            this->player.getPlayerX(), 
            this->player.getPlayerY(), 
            RADIAN(this->player.getPlayerA()) + (i * (RADIAN(this->player.getPlayerFOV()) / this->nb_rays))
            - (RADIAN(this->player.getPlayerFOV()) / 2) 
            )
        );
    }
}

std::vector<Raycast> RaycastEngine::getRays(){
    return this->rays;
}