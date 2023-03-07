#include "../headers/player.hpp"
#include <QPainter>
#include <QPaintEvent>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif




Player::Player (QWidget *parent, float x, float y) : QWidget(parent){}

void Player::paintEvent(QPaintEvent* event){
    printf("paintEvent called \n");
    QPainter painter(this);

    /* Draw the 2d map */ 
    /* Background */
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawRect(x, y, 100, 100);            

}

