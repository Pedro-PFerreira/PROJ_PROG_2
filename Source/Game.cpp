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
    int lines = maze.getDimensions()[0];
    int cols = maze.getDimensions()[1];
    unsigned int cont_robot = 0;

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
    bool answer = true;
    for (auto robot : robots)
    {
        answer = answer && robot.getStatus() == 'r';
    }
    answer = answer && player.getStatus() == 'h';
    answer = answer || player_collide() == 3;
    return answer;
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
    if (player.getStatus() == 'h')
        return true;
    return false;
}

int Game::player_collide()
{
    return 0;
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

    if (player_collide() == 0)
    {   
        char**maze_copy= maze.getMaze();
        maze_copy[player.getCord()[0]][ player.getCord()[1]] = ' ';
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

        else if (tolower(button) == 'c')
        {
            player.setCord(player.getCord()[0] + 1, player.getCord()[1] + 1);
        }
        maze_copy[player.getCord()[0]][ player.getCord()[1]] = 'H';
        maze.refreshMaze(maze_copy);
    }

    else if (player_collide() == 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid movement. Please select another movement." << endl;
    }

    else if (player_collide() == 2)
    {
        player.changeStatus();
    }

}