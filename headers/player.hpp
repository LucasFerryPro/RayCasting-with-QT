#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QWidget>

class Player : public QWidget
{
    public:
    explicit Player(QWidget *parent = nullptr, float x = 0, float y = 0);
    void setPos(float x, float y);
    float getX();
    float getY();

    protected:
    void paintEvent(QPaintEvent* event);

    private:
    float x = 0;
    float y = 0;
    
};
#endif