#ifndef WALL_H
#define WALL_H

#include <QRectF>

class Case : public QRectF
{
    private:
        int x;
        int y;
        int w;
        int h;
        int type;

    public:
        Case(int x , int y, int type);
        Case(int x, int y, int w, int h, int type);
        ~Case();
        void setCasePos(int x, int y);
        void setCaseSize(int w, int h);
        int getCaseX();
        int getCaseY();
        int getCaseW();
        int getCaseH();
        void setType(int t);
        int getType();
};
#endif