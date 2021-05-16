//Grupo

#include "Player.hpp"

Player::Player()
{
    x = x;
    y = y;
    status = status;
}

void Player::setCord (unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

void Player::setStatus(char status) 
{
    this -> status = status;
}

void Player::changeStatus() 
{
    status = 'h';
}

void Player::changeCord(unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Player::getCord()
{
    vector<unsigned int> coord = {};
    coord.push_back(x);
    coord.push_back(y);
    return coord;
}

char Player::getStatus()
{
    return status;
}