//Grupo

#include "Robot.hpp"

Robot::Robot()
{
    x = 0;
    y = 0;
    status = 'R';
    id = 1;
}

void Robot::setCord (unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

void Robot::setStatus(char status) 
{
    this -> status = status;
}

void Robot::setID(unsigned int id)
{
    this -> id = id;
}

void Robot::changeStatus(char s) 
{
    status = s;
}

void Robot::changeCord(unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Robot::getCord()
{
    vector<unsigned int> coord = {};
    coord.push_back(x);
    coord.push_back(y);
    return coord;
}

char Robot::getStatus() const
{
    return status;
}

unsigned int Robot::getID() const
{
    return id;
}