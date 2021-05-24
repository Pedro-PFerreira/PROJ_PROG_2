//Grupo

#ifndef MAZE_DEFINED
#define MAZE_DEFINED

#include "Post.hpp"
#include "Portal.hpp"

class Maze // This class Maze will ensure the creation of all elements of the maze, such as robots, the player, the posts and the portals too. In the "Maze.cpp" explains how each method of the class works.
{
    public:
    Maze();
    string getName() const;
    void setDimension(unsigned int lines, unsigned int cols);
    void setName(string name);
    void includePost(Post post);
    void includePortal(Portal portal);
    vector<unsigned int> getDimensions() const;
    vector<Post> getPosts() const;
    vector<Portal> getPortals() const;
    void changePost(int x, int y);

    private:
    unsigned int lines;
    unsigned int cols;
    string name;
    vector<Post> posts;
    vector<Portal> portals;

};

#endif