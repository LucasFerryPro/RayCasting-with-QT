 #include <QRectF>

class Raycast: public QRectF
{
private:
    int x1;
    int y1;
    int x2;
    int y2;
    double length;
    double angle;

public:
    Raycast();
    Raycast(int x1, int y1, double angle);
    ~Raycast();

    void setRaycast(int x1, int y1, double angle);
    double getRaycastLength();
    double getRaycastAngle();
};
