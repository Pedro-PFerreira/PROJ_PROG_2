//Grupo

#ifndef GAME_DEFINED
#define GAME_DEFINED

#include "Maze.hpp"
#include "Player.hpp"
#include "Robot.hpp"

class Game
{
    public:
    Game();
    void createMaze(int number_maze);
    void printMaze();
    void createObjects();

    private:
    Player player;
    vector<Robot> robots;
    Maze maze;
    
    // void movimento dos robots
    // void movimento do player
    // bool colisions robot
    // bool colision robot
};

#endif