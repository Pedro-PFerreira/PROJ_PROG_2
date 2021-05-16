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
    void test(); // Função que só serve para ver se tudo é metido a objectos correctamente, apagar quando tudo estiver ok!

    // void movimento dos robots
    // void movimento do player
    // bool colisions robot
    // bool colision robot

    private:
    Player player;
    vector<Robot> robots;
    Maze maze;
};

#endif