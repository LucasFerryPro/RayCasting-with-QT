#include <QApplication>
#include <QMainWindow>
#include <../headers/scene2d.hpp>
#include <../headers/scene3d.hpp>
#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>
#include <QVBoxLayout>
#include <QGraphicsView>

int world_map[WORLD_SIZE][WORLD_SIZE] = {
    { 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1 },
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    window->setWindowTitle("Raycasting with QT");

    Player player(60,100);
    RaycastEngine re(player,100);
    QGraphicsView *view3d = new QGraphicsView();
    QGraphicsView *view2d = new QGraphicsView(view3d);
    
    Scene3D *scene3d = new Scene3D();
    Scene2D *scene2d = new Scene2D(world_map, player, re, scene3d); 

    view3d->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding); 

    scene2d->draw();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(view3d);

    view3d->setScene(scene3d);
    view2d->setScene(scene2d);        
    
    window->setLayout(layout);

    view2d->move(30,30);

    window->setFixedSize(WHEIGHT*4, WHEIGHT*4);

    window->show();
    return app.exec();
}