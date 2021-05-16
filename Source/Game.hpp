//Grupo

#include "Player.hpp"
#include "Robot.hpp"
#include "Maze.hpp"

class Game 
{
    public:
    Game();
    void createMaze(int number_maze);
    void createObjects();

    private:
    Player player;
    vector<Robot> robots;
    Maze maze_something;
};