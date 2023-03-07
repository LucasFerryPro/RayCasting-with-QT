#include "../headers/mainwindow.hpp"
#include <QPainter>
#include <QPaintEvent>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define LINE 2
#define WWIDTH 1600
#define WHEIGHT 800

#define WORLD_SIZE 8

#define CASE WHEIGHT/WORLD_SIZE

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

MainWindow::MainWindow (QWidget *parent) : QWidget(parent){
    setFixedSize(WWIDTH+1, WHEIGHT+1);
    setWindowTitle("Raycasting with QT");
}

void MainWindow::paintEvent(QPaintEvent* event){
    printf("paintEvent called \r \n");
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

