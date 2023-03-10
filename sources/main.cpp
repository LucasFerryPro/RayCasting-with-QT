#include <QApplication>
#include <QMainWindow>
#include <../headers/view2d.hpp>
#include <../headers/scene2d.hpp>
#include <../headers/view3d.hpp>
#include <../headers/scene3d.hpp>
#include <../headers/player.hpp>
#include <../headers/raycast.hpp>
#include <../headers/raycast_engine.hpp>
#include <../headers/define.hpp>

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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow window;

    window.setFixedSize(WWIDTH, WHEIGHT);
    window.setWindowTitle("Raycasting with QT");

    Scene2D scene2d(&window); 
    View2D view(&scene2d);

    scene2d.draw(world_map);

    // Scene3D scene3d(&window);
    // View3D view3d(&scene3d);

    window.setCentralWidget(&view);

    window.show();
    return app.exec();
}