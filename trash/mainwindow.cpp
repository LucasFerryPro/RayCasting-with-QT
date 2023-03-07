#include "mainwindow.hpp"
#include <QPainter>
#include <QPaintEvent>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define LINE 2
#define WWIDTH 1600
#define WHEIGHT 800

#define WORLD_SIZE 8

#define CASE WHEIGHT/WORLD_SIZE

#define PLAYER_SIZE 15

int world_map[WORLD_SIZE][WORLD_SIZE] = {
    { 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1 },
};

/* Player Variables */
float player_x = 450.0;
float player_y = 650.0;
float player_a = 0.0;

MainWindow::MainWindow (QWidget *parent) : QWidget(parent){
    setFixedSize(WWIDTH+1, WHEIGHT+1);
    setWindowTitle("Raycasting with QT");
}

void MainWindow::drawPlayer(QPainter &painter){
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(player_x, player_y, PLAYER_SIZE, PLAYER_SIZE);
    painter.drawLine(
        player_x+PLAYER_SIZE/2,
        player_y+PLAYER_SIZE/2, 
        player_x+PLAYER_SIZE/2+cos(player_a)*30, 
        player_y+PLAYER_SIZE/2+sin(player_a)*30);
}

void MainWindow::paintEvent(QPaintEvent* event){
    printf("paintEvent called \n");
    QPainter painter(this);

    /* Draw the 2d map */ 
    /* Background */
    painter.setPen(QPen(Qt::darkGray, 1, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::darkGray, Qt::SolidPattern));
    painter.drawRect(0, 0, WWIDTH/2, WHEIGHT);
    /* End of background */

    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            if(world_map[j][i] == 1){
                painter.setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap));
                painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
                painter.drawRect(i*CASE+LINE, j*CASE+LINE, CASE-LINE*2, CASE-LINE*2);
            }else if (world_map[j][i] == 0){
                painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
                painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
                painter.drawRect(i*CASE+LINE, j*CASE+LINE, CASE-LINE*2, CASE-LINE*2);
            }
            
        }
    }
    /* End of draw the 2d map */

    /* Draw the Player */
    drawPlayer(painter);
    
    /* End of Draw the Player */

    /* Draw the 3d map */
    painter.setRenderHint(QPainter::Antialiasing);
    /* End of draw the 3d map */

    /* Separators */
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawRect(0, 0, LINE, WHEIGHT);
    painter.drawRect(WHEIGHT-LINE, 0, LINE, WHEIGHT);
    painter.drawRect(WWIDTH-LINE, 0, LINE, WHEIGHT);
    painter.drawRect(0, 0, WWIDTH, LINE);
    painter.drawRect(0, WHEIGHT-LINE, WWIDTH, LINE);
    /* End of separator */
    
}

