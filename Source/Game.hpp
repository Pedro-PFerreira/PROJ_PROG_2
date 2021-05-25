//T04_G04

#ifndef GAME_DEFINED
#define GAME_DEFINED

#include "Maze.hpp"
#include "Player.hpp"
#include "Robot.hpp"

// This class Game will ensure the interactions of the various objects, such as robots, the player, the posts, according to the game's rules. In the "Game.cpp" explains how each method of the class works.

class Game
{
    public:
    Game();
    void printMaze();
    void createObjects(int number_maze);
    void robot_moves();
    void player_moves();
    bool valid_button(char button) const;
    bool isAlive() const;
    bool end() const;
    int player_collide(char button);
    char nextChar(int x, int y) const;

    private:
    Player player;
    Maze maze;
    vector<Robot> robots;
};

#endif