//Grupo

//Maze's classes.

#include "Maze.hpp"
#include "Post.cpp"
#include "Portal.cpp"

Maze::Maze() /** This is the constructor of the class Maze. **/
{
    lines = 0;
    cols = 0;
    posts = {};
    portals = {};
    name = "";
}

void Maze::setDimension(unsigned int lines, unsigned int cols) /** This method defines the dimensions of the maze by setting the values @param lines and @param cols as the number of lines and collumns of the maze, respectively. **/
{
    this -> lines = lines;
    this -> cols = cols;
}

void Maze::setName(string name) /** This method defines the name of the maze by setting it the name of the chosen maze by the user ("MAZE_01.TXT" for example.) **/
{
    this -> name = name;
}

vector<unsigned int> Maze::getDimensions() const /** This method returns the dimensions of the maze through a vector which elements are the number of the lines and collumns of the chosen maze, by its order. **/
{
    vector<unsigned int> dimensions = {};
    dimensions.push_back(lines);
    dimensions.push_back(cols);
    return dimensions;
}

void Maze::includePost(Post post) /** This method receives adds a new post to the vector which contains all posts of the maze **/
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

void Maze::changePost(int x, int y)
{
    for (auto &post: posts)
    {
        if (post.getCord()[0] == x && post.getCord()[1] == y)
        {           
            post.change_Status();
        }
    }
}
vector<Portal> Maze::getPortals() const
{
    return portals;
}