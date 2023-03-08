#include <QRectF>

class Player: public QRectF{
    private:
        int player_x;
        int player_y;
        double player_a;

    public:
        Player();
        Player(int x , int y);
        Player(int x, int y, double a);
        ~Player();
        void setPlayerPos(int x, int y);
        void setPlayerAngle(double a);
        int getPlayerX();
        int getPlayerY();
        double getPlayerA();
};