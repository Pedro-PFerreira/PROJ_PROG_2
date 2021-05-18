//Grupo

#include "Portal.hpp"

Portal::Portal()
{
    x = 0;
    y = 0;
}

void Portal::setCord (unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Portal::getCoords() const
{
    vector<unsigned int> coords;
    coords.push_back(x);
    coords.push_back(y);
    return coords;
}