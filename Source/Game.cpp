// Grupo

#include "Game.hpp"

Game::Game()
{
    maze = maze;
    player = player;
    robots = robots;
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
    int lines = maze.getDimensions()[0];
    int cols = maze.getDimensions()[1];
    unsigned int cont_robot = 0;

    for (int line = 0 ; line < lines ; line++ )
    {
        for (int col = 0 ; col < cols ; col++ )
        {   
            char current_item = maze.getMaze()[line][col];
            if (current_item == 'R' || current_item == 'r')
            {   
                Robot robot = Robot();
                robot.setCord(line, col);
                robot.setStatus(current_item);
                robot.setID(cont_robot);
                cont_robot++;
                robots.push_back(robot);
            }
        }
    }
}