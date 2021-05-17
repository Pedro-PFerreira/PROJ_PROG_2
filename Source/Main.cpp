//Grupo

#include <iostream>
#include <vector>
#include <iostream>
#include <limits>
#include <ctime>

#include "Show_Menu.cpp"
#include "Maze.cpp"
#include "Game.cpp"
#include "Player.cpp"

using namespace std;

int main()
{   
    srand(time(NULL));
    bool want_play = false;
    int number_maze, time1, time2;

    while (!want_play)
    {
        Menu(want_play, number_maze);
    }

    Game game;
    game.createMaze(number_maze);
    game.createObjects();

    time1 = time(NULL);
    while (!game.end()) 
    {
        game.player_moves();
        game.printMaze();
    }
    time2 = time(NULL);
    
    if (game.isAlive())
    {
        cout << "Congratulations, you won!" << endl;
        write_file(time2-time1, number_maze);
    }

    else
    {
        cout << "You lost!";
    }

    return 0;
}