//Grupo

#include "Robot.hpp"
unsigned int Robot::numRobots = 0;

Robot::Robot()
{
    x = 0;
    y = 0;
    status = 'R';
    numRobots++;
    id = numRobots;
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