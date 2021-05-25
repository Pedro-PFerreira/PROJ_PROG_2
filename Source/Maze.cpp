//T04_G04

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

void Maze::setDimension(int lines, int cols) /** This method defines the dimensions of the maze by setting the values @param lines and @param cols as the number of lines and collumns of the maze, respectively. **/
{
    this -> lines = lines;
    this -> cols = cols;
}

void Maze::setName(string name) /** This method defines the name of the maze by setting it the name of the chosen maze by the user ("MAZE_01.TXT" for example). **/
{
    this -> name = name;
}

vector<int> Maze::getDimensions() const /** This method returns the dimensions of the maze through a vector which elements are the number of the lines and collumns of the chosen maze, by its order. **/
{
    vector<int> dimensions = {};
    dimensions.push_back(lines);
    dimensions.push_back(cols);
    return dimensions;
}

void Maze::includePost(Post post) /** This method adds a new post to the vector which contains all posts of the maze. **/
{
    posts.push_back(post);
}

void Maze::includePortal(Portal portal) /** This method adds a new post to the vector which contains all portals of the maze. **/
{
    portals.push_back(portal);
}

vector<Post> Maze::getPosts() const /** This method returns a vector @param posts, which contains all the posts of the maze. **/
{
    return posts;
}

void Maze::changePost(int x, int y) /** This method changes the status of the post which coordinates are @param x and @param y of the vector @param posts **/
{
    for (auto &post: posts)
    {
        if (post.getCord()[0] == x && post.getCord()[1] == y)
        {           
            post.change_Status();
        }
    }
}
vector<Portal> Maze::getPortals() const /** This method returns a vector @param portals, which contains all the portals of the maze. **/
{
    return portals;
}