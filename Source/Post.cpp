//Grupo

#include "Post.hpp"

Post :: Post()
{
    x = 0;
    y = 0;
    status = '*';
}

void Post::setCord(unsigned int x, unsigned int y)
{
    this -> x = x;
    this -> y = y;
}

void Post::set_Status(char status)
{
    this -> status = status;
}

vector <unsigned int> Post::getCord() const
{
    vector <unsigned int> cord = {};
    cord.push_back(x);
    cord.push_back(y);
    return cord;
}

void Post::change_Status()
{
    if (status == '*')
        status = '+';
}

char Post::get_Status() const
{
    return status;
}