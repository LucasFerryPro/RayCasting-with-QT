#include <QRectF>

class player: public QRectF{
    public:
        player();
        ~player();
        void setPlayerPos(int x, int y);
        void setPlayerAngle(double a);
        int getPlayerX();
        int getPlayerY();
        double getPlayerA();
    private:
        int player_x;
        int player_y;
        double player_a;
};