//Grupo

#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "Maze.hpp"
#include "Post.cpp"
#include "Portal.cpp"

Maze::Maze()
{
    lines = lines;
    cols = cols;
    posts = posts;
    portals = portals;
}

void Maze::setDimension(unsigned int lines, unsigned int cols)
{
    this -> lines = lines;
    this -> cols = cols;
}

void Maze::setName(string name) 
{
    this -> name = name;
}

vector<unsigned int> Maze::getDimensions() 
{
    vector<unsigned int> dimensions = {};
    dimensions.push_back(lines);
    dimensions.push_back(cols);
    return dimensions;
}

void Maze::includePost(Post post)
{
    posts.push_back(post);
}

void Maze::includePortal(Portal portal)
{
    portals.push_back(portal);
}

vector<Post> Maze::getPosts()
{
    return posts;
}

vector<Portal> Maze::getPortals()
{
    return portals;
}