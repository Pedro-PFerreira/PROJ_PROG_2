// Grupo

// Game's method
#include "Game.hpp"
#include "Robot.cpp"
#include "Post.hpp"
#include <iostream>
using namespace std;

Game::Game() /** This is the contructor of the class Game() **/
{
    maze = maze;
    player = player;
    robots = robots;
}

void Game::createMaze(int number_maze) /** This method creates the maze selected by the user thanks to the number chosen by him / her **/
{
    maze.setMaze(number_maze);
}

void Game::printMaze() /** This method shows on the screen the maze selected by the user **/
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

void Game::createObjects() /** This method creates the various elements of the game (such as posts, the robots and the player) by their corresponding symbol: 'h'/'H' represents the player, 'R'/'r' represents the robots and the '*' / '+' symols correspond to the fences. **/
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

bool Game::end() /** This method verifies if the has already ended, by checking if al the robots are destroyed (that is, each robot's status is represented by an 'r'); iit checks if the player is alive, thanks to the isAlive() function or if the players has won the game. **/
{
    bool all_dead = true;
    for (auto robot : robots)
    {
        all_dead = all_dead && robot.getStatus() == 'r';
    }
    return all_dead || !isAlive() || player.Win();
}

bool Game::valid_button(char command) /** This method verifies if the user has inputed a valid button, that is, if the character typed by him/her corresponds to one of the characters in @param allowed_commands. **/
{
    vector<char> allowed_commands = {'q', 'w', 'e', 'd', 'c', 'x', 'z', 'a', 's'};
    for (char attemp : allowed_commands)
    {
        if (tolower(command) == attemp)
            return true;
    }
    return false;
}

bool Game::isAlive() /** This method veriifies if the player is still alive, in other words, it checks if the status of the player correponds to a 'H'. It returns true if so, otherwise, it returns false. **/
{
    return player.getStatus() == 'H';
}

int Game::player_collide(char button) /** This method verifies if the player collides with other object (with a fence or a robot), returning 0 if it is a valid one, 1 if he/she collided with a non-electrified fence or a stuck robot, 2 if he has collided with a live robot or an electrified, meaning that he/she has lost the game, 3 if he/she finds an exit to escape the maze ('O').**/
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
    if (next_char == ' ' || next_char == 'H')
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

void Game::player_moves() /** This method assures the the moevement of the player, according to the letter typed by the user. The validaty is assured by the player_colllide() function. **/
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

void Game::robot_moves() /** This method assures the movement of the robots, according to the movement of the player. It also updates their status in each move, depending on if they had collided with other object (player or fences). **/
{
    for (auto &robot : robots)
    {   
        char ** copy_maze = maze.getMaze();
        if (!end() && robot.getStatus() == 'R' && copy_maze[robot.getCord()[0]][robot.getCord()[1]] == 'R')
        {
            int dist_v, dist_h;

            dist_v = robot.getCord()[0] - player.getCord()[0];

            dist_h = robot.getCord()[1] - player.getCord()[1];

            unsigned int new_x = robot.getCord()[0];

            unsigned int new_y = robot.getCord()[1];

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
        }
        else if (copy_maze[robot.getCord()[0]][robot.getCord()[1]] == 'r')
        {
            robot.changeStatus('r');          
        }
        maze.refreshMaze(copy_maze);  
    }
}