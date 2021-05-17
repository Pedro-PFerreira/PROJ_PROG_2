// Grupo

#include "Game.hpp"
#include "Robot.cpp"
#include "Post.hpp"
#include <iostream>
using namespace std;

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

    for (int line = 0; line < lines; line++)
    {
        for (int col = 0; col < cols; col++)
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
    unsigned int cont_robot = 1;

    for (int line = 0; line < lines; line++)
    {
        for (int col = 0; col < cols; col++)
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

bool Game::end()
{
    bool all_dead = true;
    for (auto robot : robots)
    {
        all_dead = all_dead && robot.getStatus() == 'r';
    }
    return all_dead || !isAlive() || player.Win();
}

bool Game::valid_button(char command)
{
    vector<char> allowed_commands = {'q', 'w', 'e', 'd', 'c', 'x', 'z', 'a', 's'};
    for (char attemp : allowed_commands)
    {
        if (tolower(command) == attemp)
            return true;
    }
    return false;
}

bool Game::isAlive()
{
    return player.getStatus() == 'H';
}

int Game::player_collide(char button)
{
    button = tolower(button);
    unsigned int x = player.getCord()[0];
    unsigned int y = player.getCord()[1];

    if (button == 'q' || button == 'w' || button == 'e')
        x--;
    if (button == 'z' || button == 'x' || button == 'c')
        x++;
    if (button == 'q' || button == 'a' || button == 'z')
        y--;
    if (button == 'e' || button == 'd' || button == 'c')
        y++;

    char next_char = maze.getMaze()[x][y];
    if (next_char == ' ')
        return 0;
    if (next_char == '+' || next_char == 'r')
        return 1;
    if (next_char == '*' || next_char == 'R')
        return 2;
    if (next_char == 'O')
    {
        player.changeWin();
        return 3;
    }
    return 4;
}

void Game::player_moves()
{
    char button;

    cout << "The robots are chasing you! Press a command to run away from them: " << endl;
    cin >> button;

    if (cin.eof())
    {
        exit(0);
    }

    while (!valid_button(button) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printMaze();
        cerr << "Invalid command. Please choose another button." << endl;
        cin >> button;
        if (cin.eof())
        {
            exit(0);
        }
    }

    if (cin.eof())
    {
        exit(0);
    }

    if (!player_collide(button) || player_collide(button) == 3)
    {
        char **maze_copy = maze.getMaze();
        maze_copy[player.getCord()[0]][player.getCord()[1]] = ' ';
        if (tolower(button) == 'w')
        {
            player.setCord(player.getCord()[0] - 1, player.getCord()[1]);
        }

        else if (tolower(button) == 'q')
        {
            player.setCord(player.getCord()[0] - 1, player.getCord()[1] - 1);
        }

        else if (tolower(button) == 'e')
        {
            player.setCord(player.getCord()[0] - 1, player.getCord()[1] + 1);
        }

        else if (tolower(button) == 'a')
        {
            player.setCord(player.getCord()[0], player.getCord()[1] - 1);
        }

        else if (tolower(button) == 's')
        {
            player.setCord(player.getCord()[0], player.getCord()[1]);
        }

        else if (tolower(button) == 'd')
        {
            player.setCord(player.getCord()[0], player.getCord()[1] + 1);
        }

        else if (tolower(button) == 'z')
        {
            player.setCord(player.getCord()[0] + 1, player.getCord()[1] - 1);
        }

        else if (tolower(button) == 'x')
        {
            player.setCord(player.getCord()[0] + 1, player.getCord()[1]);
        }

        else if (tolower(button) == 'w')
        {
            player.setCord(player.getCord()[0] + 1, player.getCord()[1] + 1);
        }

        maze_copy[player.getCord()[0]][player.getCord()[1]] = 'H';
        maze.refreshMaze(maze_copy);

        if (isAlive() && !player.Win())
        {
            robot_moves();
        }
    }

    else if (player_collide(button) == 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid movement. Please select another movement." << endl;
    }

    else if (player_collide(button) == 2)
    {
        player.changeStatus();
        char **copy_maze = maze.getMaze();
        copy_maze[player.getCord()[0]][player.getCord()[1]] = player.getStatus();
        maze.refreshMaze(copy_maze);
    }
}

void Game::robot_moves()
{
    for (auto robot : robots)
    {   
        char ** copy_maze = maze.getMaze();
        if (!end() && robot.getStatus() == 'R' && copy_maze[robot.getCord()[0]][robot.getCord()[1]] == 'R')
        {
            int dist_v, dist_h;

            dist_v = robot.getCord()[0] - player.getCord()[0];

            dist_h = robot.getCord()[1] - player.getCord()[1];

            unsigned int new_x = robot.getCord()[0];

            unsigned int new_y = robot.getCord()[1];
            //cout << "Dist H: " << dist_h << " and dist V: " << dist_v << endl;
            //cout << new_x << " and " << new_y << endl;
            if (dist_h > 0 && dist_v == 0)
            {
                new_y--;
            }

            else if (dist_h == 0 && dist_v < 0)
                new_x++;
            else if (dist_h < 0 && dist_v == 0)
                new_y++;
            else if (dist_h == 0 && dist_v > 0)
                new_x--;
            else if (dist_h > 0 && dist_v < 0)
            {
                new_y--;
                new_x++;
            }

            else if (dist_h < 0 && dist_v < 0)
            {
                new_x++;
                new_y++;
            }
            else if (dist_h < 0 && dist_v > 0)
            {
                new_x--;
                new_y++;
            }
            else if (dist_h > 0 && dist_v > 0)
            {
                new_x--;
                new_y--;
            }
            //cout << new_x << " and " << new_y << endl << endl;
            if (copy_maze[new_x][new_y] == ' ')
            {
                copy_maze[robot.getCord()[0]][robot.getCord()[1]] = ' ';
                copy_maze[new_x][new_y] = 'R';
                robot.changeCord(new_x,new_y);            
            }

            else if (copy_maze[new_x][new_y] == '*')
            {   
                copy_maze[robot.getCord()[0]][robot.getCord()[1]] = 'r';
                robot.changeStatus('r');
            }
            else if (copy_maze[new_x][new_y] == 'H')
            {
                copy_maze[new_x][new_y] = 'h';            
                player.changeStatus();
 
            }
            else
            {
                copy_maze[robot.getCord()[0]][robot.getCord()[1]] = ' ';
                copy_maze[new_x][new_y] = 'r';
                robot.changeStatus('r');
            }
            maze.refreshMaze(copy_maze); 
        }
        else if (copy_maze[robot.getCord()[0]][robot.getCord()[1]] == 'r')
        {
            robot.changeStatus('r');          
        }
        maze.refreshMaze(copy_maze);  

        cout << "Robot " << robot.getID() << " status " << robot.getStatus() << endl;
    }
}