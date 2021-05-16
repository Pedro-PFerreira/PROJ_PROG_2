//Grupo

#include "Post.cpp"

class Maze 
{
    public:
    Maze();
    char ** getMaze();
    string getName();
    void setMaze(int number_maze);
    void setDimension(unsigned int lines, unsigned int cols);
    void setName(string name);
    void includePost(Post new_post);
    vector<unsigned int> getDimensions();
    vector<Post> getPosts();

    private:
    unsigned int lines;
    unsigned int cols;
    vector<Post> posts;
    string name;
    char **maze_content;
};