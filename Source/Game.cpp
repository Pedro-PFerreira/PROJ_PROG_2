// Grupo

#include "Game.hpp"
#include <iostream>
Game::Game()
{
    maze = maze;
}

void Game::createMaze(int number_maze) 
{
    maze.setMaze(number_maze);
}   

void Game::printMaze()
{
    int lines = maze.getDimensions()[0];
    int cols = maze.getDimensions()[1];

    for (int line = 0 ; line < lines ; line++ )
    {
        for (int col = 0 ; col < cols ; col++ )
        {
            cout << maze.getMaze()[line][col];
        }
        cout << endl;
    }
}

void Game::createObjects()
{   
    printMaze();
}