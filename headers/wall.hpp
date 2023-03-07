#include <QRectF>

class Wall : public QRectF
{
    public:
        Wall();
        ~Wall();
        void setWallPos(int x, int y);
        void setWallSize(int w, int h);
        int getWallX();
        int getWallY();
        int getWallW();
        int getWallH();
    private:
        int wall_x;
        int wall_y;
        int wall_w;
        int wall_h;
};