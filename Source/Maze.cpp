//Grupo

#include "Maze.hpp"
#include "Post.cpp"
#include "Portal.cpp"

Maze::Maze()
{
    lines = 0;
    cols = 0;
    posts = {};
    portals = {};
    name = "";
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

vector<unsigned int> Maze::getDimensions() const 
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

vector<Post> Maze::getPosts() const
{
    return posts;
}

vector<Portal> Maze::getPortals() const
{
    return portals;
}