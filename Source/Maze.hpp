//Grupo

#ifndef MAZE_DEFINED
#define MAZE_DEFINED


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
    void setDimension(unsigned int lines, unsigned int cols);
    void setName(string name);
    vector<unsigned int> getDimensions();

    private:
    unsigned int lines;
    unsigned int cols;
    string name;
    char **maze_content;
};

#endif