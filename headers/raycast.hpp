#ifndef RAYCAST_H
#define RAYCAST_H

#include <QLineF>
#include <QPainterPath>

class Raycast: public QLineF
{
private:
    QPointF start;
    QPointF end;
    double angle;
    int number;

public:
    Raycast();
    Raycast(int x1, int y1, int x2, int y2, double angle, int number);
    ~Raycast();

    QPainterPath shape() const;

    double getRaycastLength();
    int getRaycastNumber();
};
#endif