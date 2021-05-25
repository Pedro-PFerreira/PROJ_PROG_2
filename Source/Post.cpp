//T04_G04

#include "Post.hpp"

Post :: Post() /** This is the contructor of the class Post **/
{
    x = 0;
    y = 0;
    status = '*';
}

void Post::setCord(int x, int y) /** This method will define the post's coordinates on the maze, according the @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

void Post::set_Status(char status) /** This method will define the post's status, according to @param status ('*' or '+') **/
{
    this -> status = status;
}

vector <int> Post::getCord() const /** This method returns the current coordinates @param x and @param y of the post, by returning a vector @param cord. **/
{
    vector <int> cord = {};
    cord.push_back(x);
    cord.push_back(y);
    return cord;
}

void Post::change_Status() /** This method changes the post's status to '+'. This method will be called when the player or a robot collide with an electrified fence. **/
{
    if (status == '*')
        status = '+';
}

char Post::get_Status() const /** This method returns the current status of the post. **/
{
    return status;
}