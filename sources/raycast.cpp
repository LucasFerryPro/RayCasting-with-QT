#include <../headers/raycast.hpp>
#include <cmath>

Raycast::Raycast(){};

Raycast::Raycast(int x, int y, double angle){
    this->start.setX(x);
    this->start.setY(y);
    this->angle = angle;
    this->length = 100;
    this->end.setX(this->start.x() + this->length * cos(this->angle));
    this->end.setY(this->start.y() + this->length * sin(this->angle));
    setLine(this->start.x(), this->start.y(), this->end.x(), this->end.y());
}

QPainterPath Raycast::shape() const
{
    QPainterPath path(this->start);
    path.lineTo(this->end);
    return path;
}

Raycast::~Raycast(){};

