#include <../headers/raycast.hpp>
#include <cmath>
#include <../headers/define.hpp>

Raycast::Raycast(){};

Raycast::Raycast(int x1, int y1, int x2, int y2, double angle){
    this->start.setX(x1);
    this->start.setY(y1);
    this->angle = angle;
    this->length = 100;
    this->end.setX(x2);
    this->end.setY(y2);
    // this->end.setX(this->start.x() + this->length * cos(this->angle));
    // this->end.setY(this->start.y() + this->length * sin(this->angle));
    setLine(this->start.x(), this->start.y(), this->end.x(), this->end.y());
}

QPainterPath Raycast::shape() const
{
    QPainterPath path(this->start);
    path.lineTo(this->end);
    return path;
}

void setMap(int map[WORLD_SIZE][WORLD_SIZE]){

}

Raycast::~Raycast(){};

