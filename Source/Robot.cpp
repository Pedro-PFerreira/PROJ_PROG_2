//Grupo

#include <vector>
#include "Robot.hpp"
using namespace std;

Robot :: Robot()
{
    x = x;
    y = y;
    status = status;
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

void Robot::changeStatus() 
{
    status = 'r';
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

char Robot::getStatus()
{
    return status;
}