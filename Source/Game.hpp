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
    int player_collide(char button);
    bool valid_button(char button);
    bool isAlive();

    private:
    Player player;
    vector<Robot> robots;
    Maze maze;
};

#endif