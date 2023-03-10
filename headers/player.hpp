#ifndef PLAYER_H
#define PLAYER_H

#include <QRectF>
#include <cmath>

class Player: public QRectF{
    private:
        double player_x;
        double player_y;
        double player_a;
        double player_speed;
        double player_turn_speed;
        float player_fov;

    public:
        Player();
        Player(double x , double y);
        Player(double x, double y, double a);
        Player(double x, double y, double a, double s, double ts, float fov);
        ~Player();
        void setPlayerPos(double x, double y);
        void setPlayerAngle(double a);
        void setPlayerSpeed(double s);
        void setPlayerTurnSpeed(double ts);
        void setPlayerFOV(float fov);
        double getPlayerX();
        double getPlayerY();
        double getPlayerA();
        double getPlayerSpeed();
        double getPlayerTurnSpeed();
        float getPlayerFOV();
};
#endif