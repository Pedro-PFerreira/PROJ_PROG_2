// Grupo

#include "Game.hpp"

Game::Game()
{
    maze = maze;
}

void Game::createMaze(int number_maze) 
{
    maze.setMaze(number_maze);
}   

void Game::createObjects()
{   
    int lines = maze.getDimensions()[0];
    int cols = maze.getDimensions()[1];
    cout << "lines " << lines << " and cols " << cols << endl;

    for (int line = 0 ; line < lines ; line++ )
    {
        for (int col = 0 ; col < cols ; col++ )
        {
            cout << maze.getMaze()[line][col];
        }
        cout << endl;
    }
}