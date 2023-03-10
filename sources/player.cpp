#include <../headers/player.hpp>

Player::Player()
{
    this->player_x = 0;
    this->player_y = 0;
    this->player_a = 0;
    this-> player_speed = 1;
    this->player_turn_speed = 1;
    this->player_fov = 60;
    setRect(0,0,10,10);
};

Player::Player(int x , int y)
{
    this->player_x = x;
    this->player_y = y;
    this->player_a = 0;
    this-> player_speed = 1;
    this->player_turn_speed = 1;
    this->player_fov = 60;
    setRect(x-5,y-5,10,10);
};

Player::Player(int x, int y, double a)
{
    this->player_x = x;
    this->player_y = y;
    this->player_a = a;
    this-> player_speed = 1;
    this->player_turn_speed = 1;
    this->player_fov = 60;
    setRect(x-5,y-5,10,10);
};

Player::Player(int x, int y, double a, double s, double ts, float fov)
{
    this->player_x = x;
    this->player_y = y;
    this->player_a = a;
    this-> player_speed = s;
    this->player_turn_speed = ts;
    this->player_fov = fov;
    setRect(x-5,y-5,10,10);
};

Player::~Player(){};

void Player::setPlayerPos(int x, int y){
    this->player_x = x;
    this->player_y = y;
};

void Player::setPlayerAngle(double a){
    this->player_a = a;
};

void Player::setPlayerSpeed(double s){
    this->player_speed = s;
};

void Player::setPlayerTurnSpeed(double ts){
    this->player_turn_speed = ts;
};

void Player::setPlayerFOV(float fov){
    this->player_fov = fov;
};

int Player::getPlayerX(){
    return this->player_x;
};

int Player::getPlayerY(){
    return this->player_y;
};

double Player::getPlayerA(){
    return this->player_a;
};

double Player::getPlayerSpeed(){
    return this->player_speed;
};

double Player::getPlayerTurnSpeed(){
    return this->player_turn_speed;
};

float Player::getPlayerFOV(){
    return this->player_fov;
};