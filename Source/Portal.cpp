//Grupo

#include "Portal.hpp"
#include <vector>
using namespace std;

Portal::Portal()
{
    x = x;
    y = y;
}

void Portal::setCord (unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Portal::getCoords() 
{
    vector<unsigned int> coords;
    coords.push_back(x);
    coords.push_back(y);
    return coords;
}