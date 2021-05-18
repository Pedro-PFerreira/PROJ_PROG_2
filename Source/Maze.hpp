//Grupo

#ifndef MAZE_DEFINED
#define MAZE_DEFINED

#include "Post.hpp"
#include "Portal.hpp"

class Maze 
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

    private:
    unsigned int lines;
    unsigned int cols;
    string name;
    vector<Post> posts;
    vector<Portal> portals;

};

#endif