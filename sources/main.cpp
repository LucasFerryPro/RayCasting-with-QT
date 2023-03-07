#include <QApplication>
#include <QMainWindow>

#define WWIDTH 800
#define WHEIGHT 400

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow window;
    window.setFixedSize(WWIDTH, WHEIGHT);
    window.setWindowTitle("Raycasting with QT");

    

    window.show();
    return app.exec();
}