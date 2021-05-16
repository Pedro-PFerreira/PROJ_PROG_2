//Grupo

#include <iostream>
#include <vector>
#include <iostream>

#include "Show_Menu.cpp"

#include "Game.cpp"

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

    return 0;
}