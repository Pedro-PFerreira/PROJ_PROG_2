//Grupo

#include <iostream>
#include <vector>
#include <iostream>

#include "Show_Menu.cpp"
#include "Maze.cpp"
#include "Game.cpp"
#include "Player.cpp"

using namespace std;

int main()
{
    bool want_play = false;
    int number_maze;

    while (!want_play)
    {
        Menu(want_play, number_maze);
    }

    Game game;
    game.createMaze(number_maze);
    game.createObjects();

    // Para testar se tudo é feito em condições:
    game.test();

    return 0;
}