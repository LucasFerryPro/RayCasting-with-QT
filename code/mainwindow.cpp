#include "mainwindow.hpp"
#include <QPainter>
#include <QPaintEvent>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WORLD_SIZE 8
int world_map[WORLD_SIZE][WORLD_SIZE] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
};

MainWindow::MainWindow (QWidget *parent) : QWidget(parent){
    setFixedSize(800,800);
    setWindowTitle("Raycasting with QT");
}

void MainWindow::paintEvent(QPaintEvent* event){
    printf("paintEvent called \r \n");
    QPainter painter(this);

    
    /* Draw the map */ 
    // painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));

    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            if(world_map[j][i] == 1){
                printf("painting at %d, %d \r \n", i, j);
                painter.drawRect(i*100, j*100, 100, 100);
            }
        }
    }
    /* End of draw the map */
}

