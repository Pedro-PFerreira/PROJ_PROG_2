// Grupo

#include "Game.hpp"
#include "Robot.cpp"

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
            char current_char = maze.getMaze()[line][col];

            if (current_char == 'R' || current_char == 'r')
            {   
                Robot robot = Robot();
                robot.setCord(line, col);
                robot.setStatus(current_char);
                robot.setID(cont_robot);
                cont_robot++;
                robots.push_back(robot);
            }

            else if (current_char == 'H' || current_char == 'h')
            {
                player.setCord(line, col);
                player.setStatus(current_char);
            }

            else if (current_char == '*' || current_char == '+')
            {
                Post current_post = Post();
                current_post.set_Status(current_char);
                current_post.setCord(line, col);
                maze.includePost(current_post);
            }
        }
    }
}