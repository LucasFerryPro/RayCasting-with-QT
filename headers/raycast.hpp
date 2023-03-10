#ifndef RAYCAST_H
#define RAYCAST_H

#include <QLineF>
#include <QPainterPath>

class Raycast: public QLineF
{
private:
    QPointF start;
    QPointF end;
    double length;
    double angle;

public:
    Raycast();
    Raycast(int x1, int y1, double angle);
    ~Raycast();

    QPainterPath shape() const;

    double getRaycastLength();
    double getRaycastAngle();
};
#endif