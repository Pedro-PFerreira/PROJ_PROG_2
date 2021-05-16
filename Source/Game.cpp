//Grupo

#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <iostream>

#include "Game.hpp"

#include "Player.cpp"
#include "Robot.cpp"
#include "Maze.cpp"
#include "Post.cpp"

Game::Game()
{
    Maze maze = Maze();
}

void Game::createMaze(int number_maze) 
{
    maze_something.setMaze(number_maze);
}   

void Game::createObjects()
{   
    char **new_maze = maze_something.getMaze();
    int lines = maze_something.getDimensions()[0];
    int cols = maze_something.getDimensions()[1];

    for (int line = 0 ; line < lines ; lines++ )
    {
        for (int col = 0 ; col < cols ; cols++ )
        {
            cout << "Create something" << endl;
        }
    }
}