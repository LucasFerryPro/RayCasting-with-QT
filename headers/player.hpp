#ifndef PLAYER_H
#define PLAYER_H

#include <QRectF>
#include <cmath>

class Player: public QRectF{
    private:
        int player_x;
        int player_y;
        double player_a;
        double player_speed;
        double player_turn_speed;
        float player_fov;

    public:
        Player();
        Player(int x , int y);
        Player(int x, int y, double a);
        Player(int x, int y, double a, double s, double ts, float fov);
        ~Player();
        void setPlayerPos(int x, int y);
        void setPlayerAngle(double a);
        void setPlayerSpeed(double s);
        void setPlayerTurnSpeed(double ts);
        void setPlayerFOV(float fov);
        int getPlayerX();
        int getPlayerY();
        double getPlayerA();
        double getPlayerSpeed();
        double getPlayerTurnSpeed();
        float getPlayerFOV();
};
#endif