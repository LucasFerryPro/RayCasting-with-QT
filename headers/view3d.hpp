#ifndef VIEW3D_H
#define VIEW3D_H

#include <QGraphicsView>

class View3D : public QGraphicsView{
    private:

    public:
    View3D(QGraphicsScene *scene = nullptr);

};
#endif