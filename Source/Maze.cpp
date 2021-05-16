//Grupo

#include "Maze.hpp"

#include "Post.cpp"

Maze::Maze()
{
    lines = lines;
    cols = cols;
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

void Maze::setMaze(int number_maze)
{
    string name_maze = number_maze < 10 && number_maze > 0 ? "MAZE_0" + to_string(number_maze) + ".TXT" : "MAZE_" + to_string(number_maze) + ".TXT";
    setName(name_maze);

    ifstream file;
    file.open(name_maze);
    if (file.good()) 
    {
        string current_line;
        unsigned int lines, cols;
        char x;
        
        // Pegar o número de linhas e colunas
        getline(file, current_line);
        istringstream str(current_line);
        str >> lines >> x >> cols;
        setDimension(lines, cols);

        // Fazer fill para um array de todo o conteúdo, usando malloc()
        char **maze_content = (char **)malloc(lines * sizeof(char *)); 
        for (int i = 0; i < lines; i++)
            maze_content[i] = (char *)malloc(cols * sizeof(char));

        int idx = 0;
        while (idx < lines)
        {    
            getline(file, current_line);
            for (int j = 0; j < cols; j++)
            {
                maze_content[idx][j] = current_line[j];
            }
            idx++;
        }

        this -> maze_content = maze_content;
    }
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

string Maze::getName() 
{
    return name;
}

vector<Post> Maze::getPosts()
{
    return posts;
}