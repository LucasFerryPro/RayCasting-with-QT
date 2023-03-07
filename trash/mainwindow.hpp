#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
class MainWindow : public QWidget
{
    public:
    explicit MainWindow(QWidget *parent = nullptr);
    void drawPlayer(QPainter &painter);

    protected:
    void paintEvent(QPaintEvent* event);

    private:
    
};
#endif