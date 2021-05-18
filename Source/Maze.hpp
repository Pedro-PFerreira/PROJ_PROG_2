//Grupo

#ifndef MAZE_DEFINED
#define MAZE_DEFINED
    
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "Post.hpp"
#include "Portal.hpp"

class Maze 
{
    public:
    Maze();
    string getName();
    void setDimension(unsigned int lines, unsigned int cols);
    void setName(string name);
    void includePost(Post post);
    void includePortal(Portal portal);
    vector<unsigned int> getDimensions();
    vector<Post> getPosts();
    vector<Portal> getPortals();


    private:
    unsigned int lines;
    unsigned int cols;
    string name;
    vector<Post> posts;
    vector<Portal> portals;

};

#endif