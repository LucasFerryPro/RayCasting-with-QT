#include <../headers/raycast.hpp>
#include <cmath>
#include <../headers/define.hpp>

Raycast::Raycast(){};

Raycast::Raycast(int x1, int y1, int x2, int y2, double angle,int number){
    this->start.setX(x1);
    this->start.setY(y1);
    this->angle = angle;
    this->end.setX(x2);
    this->end.setY(y2);
    this->number = number;
    setLine(this->start.x(), this->start.y(), this->end.x(), this->end.y());
}

QPainterPath Raycast::shape() const
{
    QPainterPath path(this->start);
    path.lineTo(this->end);
    return path;
}

double Raycast::getRaycastLength(){
    return sqrt(pow(this->end.x() - this->start.x(),2) + pow(this->end.y() - this->start.y(),2));
}

int Raycast::getRaycastNumber(){
    return this->number;
}

Raycast::~Raycast(){};

