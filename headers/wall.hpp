#include <QRectF>

class Wall : public QRectF
{
    private:
        int wall_x;
        int wall_y;
        int wall_w;
        int wall_h;

    public:
        Wall();
        Wall(int x , int y);
        Wall(int x, int y, int w, int h);
        ~Wall();
        void setWallPos(int x, int y);
        void setWallSize(int w, int h);
        int getWallX();
        int getWallY();
        int getWallW();
        int getWallH();
};