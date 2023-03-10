#include <../headers/case.hpp>
#include <../headers/define.hpp>

Case::Case(int x , int y, int type){
    this->x = x;
    this->y = y;
    this->w = WWIDTH / 2 / WORLD_SIZE - LINE;
    this->h = WHEIGHT / WORLD_SIZE - LINE;
    this->type = type;

    setRect(x,y,this->w,this->h);
}
Case::Case(int x, int y, int w, int h, int type){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->type = type;
    setRect(x,y,w,h);
}

Case::~Case(){}

void Case::setCasePos(int x, int y){
    this->x = x;
    this->y = y;
}
void Case::setCaseSize(int w, int h){
    this->w = w;
    this->h = h;
}
int Case::getCaseX(){
    return this->x;
}
int Case::getCaseY(){
    return this->y;
}
int Case::getCaseW(){
    return this->w;
}
int Case::getCaseH(){
    return this->h;
}
void Case::setType(int t){
    this->type = t;
}
int Case::getType(){
    return this->type;
}