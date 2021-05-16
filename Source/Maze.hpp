//Grupo

#ifndef MAZE_DEFINED
#define MAZE_DEFINED

#include "Post.hpp"
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

class Maze 
{
    public:
    Maze();
    char ** getMaze();
    string getName();
    void setMaze(int number_maze);
    void refreshMaze(char **maze);
    void setDimension(unsigned int lines, unsigned int cols);
    void setName(string name);
    vector<unsigned int> getDimensions();
    void includePost(Post post);
    vector<Post> getPosts();

    private:
    unsigned int lines;
    unsigned int cols;
    string name;
    char **maze_content;
    vector<Post> posts;
};

#endif