#include <../headers/raycast_engine.hpp>
#include <../headers/raycast.hpp>
#include <../headers/define.hpp>

RaycastEngine::RaycastEngine(){
    this->player = Player();
    this->nb_rays = 0;
    this->rays = std::vector<Raycast>();
}

RaycastEngine::RaycastEngine(Player player, int nb_rays){
    this->player = player;
    this->nb_rays = nb_rays;
    this->rays = std::vector<Raycast>(nb_rays);
}

RaycastEngine::~RaycastEngine(){
    this->rays.clear();
}

void RaycastEngine::emitRay(int map[WORLD_SIZE][WORLD_SIZE]){
    this->rays.clear();
    double angle;
    for(int i = 0; i < this->nb_rays; i++){
        angle = RADIAN(this->player.getPlayerA()) + (i * (RADIAN(this->player.getPlayerFOV()) / this->nb_rays))
            - (RADIAN(this->player.getPlayerFOV()) / 2) ;
        this->rays.insert (this->rays.begin(),Raycast(
            this->player.getPlayerX(), 
            this->player.getPlayerY(), 
            getRaycastEnd(angle, map).x(),
            getRaycastEnd(angle, map).y(),
            angle,
            i
            )
        );
    }
}

void RaycastEngine::setPlayer(Player player){
    this->player = player;
}

QPointF RaycastEngine::getRaycastEnd(double angle, int map[WORLD_SIZE][WORLD_SIZE]){
    double x = this->player.getPlayerX();
    double y = this->player.getPlayerY();
    double x2 = x;
    double y2 = y;
    double step = 1;
    double dx = step * cos(angle);
    double dy = step * sin(angle);
    while(map[int(posYToCaseY(y2))][int(posXToCaseX(x2))] == 0){
        x2 += dx;
        y2 += dy;
    }
    return QPointF(x2,y2);
}

int RaycastEngine::posXToCaseX(double x){
    return floor((int(x) % WHEIGHT)/25);
}

int RaycastEngine::posYToCaseY(double y){
    return floor((int(y) % WHEIGHT)/25);
}

std::vector<Raycast> RaycastEngine::getRays(){
    return this->rays;
}