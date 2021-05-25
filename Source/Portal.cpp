//T04_G04

#include "Portal.hpp"

Portal::Portal() /** This method is the constructor of the class Portal. **/
{
    x = 0;
    y = 0;
}

void Portal::setCord (unsigned int x, unsigned int y) /** This method will define the portal's coordinates on the maze, according the @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Portal::getCoords() const /** This method returns a vector @param coords which contains the current coordinates of the portal. **/
{
    vector<unsigned int> coords;
    coords.push_back(x);
    coords.push_back(y);
    return coords;
}