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
    bool end();
    void robot_moves();
    void player_moves();
    bool robots_collide();
    int player_collide();
    bool valid_button(char button);
    bool isAlive();

    // void movimento dos robots
    // void movimento do player
    // bool colisions robot
    // bool colision robot
    //bool isAlive()

    private:
    Player player;
    vector<Robot> robots;
    Maze maze;
};

#endif