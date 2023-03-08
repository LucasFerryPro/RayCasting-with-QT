#include <QApplication>
#include <QMainWindow>
#include <../headers/view2d.hpp>
#include <../headers/scene2d.hpp>
#include <../headers/view3d.hpp>
#include <../headers/scene3d.hpp>

#define WWIDTH 800
#define WHEIGHT 400

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow window;
    window.setFixedSize(WWIDTH, WHEIGHT);
    window.setWindowTitle("Raycasting with QT");

    Scene2D scene(&window); 
    View2D view(&scene);

    Scene3D scene3d(&window);
    View3D view3d(&scene3d);

    window.setCentralWidget(&view);

    window.show();
    return app.exec();
}