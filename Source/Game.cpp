//T04_G04

#include "Game.hpp"
#include "Robot.hpp"
#include "Post.hpp"

Game::Game() /** This is the constructor of the class Game **/
{
    robots = {};
}

void Game::printMaze() /** This method shows on the screen the maze selected by the user **/
{
    int lines = maze.getDimensions()[0];
    int cols = maze.getDimensions()[1];

    for (int line = 0; line < lines; line++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << nextChar(line,col);  
        }
        cout << endl;
    }
}

void Game::createObjects(int number_maze) /** This method creates the various elements of the game (such as posts, portals, the robots and the player) by their corresponding symbol: 'h'/'H' represents the player, 'O' represents the portal, 'R'/'r' represents the robots and the '*' / '+' symbols correspond to the fences. **/
{
    string name_maze = number_maze < 10 && number_maze > 0 ? "MAZE_0" + to_string(number_maze) + ".TXT" : "MAZE_" + to_string(number_maze) + ".TXT";
    maze.setName(name_maze);

    ifstream file;
    file.open(name_maze);
    if (file.good()) 
    {
        string current_line;
        
        int lines, cols;
        char x;
        
        getline(file, current_line);
        istringstream str(current_line);
        str >> lines >> x >> cols;
        maze.setDimension(lines, cols);

        int i = 0;
        while (!file.eof())
        {    
            getline(file, current_line);
            for (int j = 0; j < cols; j++)
            {
                char current_char = current_line[j];
                if (current_char == 'R' || current_char == 'r')
                {
                    Robot robot = Robot();
                    robot.setCord(i, j);
                    robot.setStatus(current_char);
                    robots.push_back(robot);
                }

                else if (current_char == 'H' || current_char == 'h')
                {
                    player.setCord(i, j);
                    player.setStatus(current_char);
                }

                else if (current_char == '*' || current_char == '+')
                {
                    Post current_post = Post();
                    current_post.set_Status(current_char);
                    current_post.setCord(i, j);
                    maze.includePost(current_post);
                }

                else if (current_char == 'O')
                {
                    Portal current_portal = Portal();
                    current_portal.setCord(i, j);
                    maze.includePortal(current_portal);
                }

                else
                {
                    continue;
                }
            }
            i++;
        }
    }
    printMaze();
}

bool Game::end() const /** This method verifies if the has already ended, by checking if all the robots are destroyed (that is, each robot's status is represented by an 'r'); it checks if the player is alive, thanks to the isAlive() function or if the players has won the game. **/
{
    return !isAlive() || player.Win();
}

bool Game::valid_button(char command) const /** This method verifies if the user has inputed a valid button, that is, if the character typed by him/her corresponds to one of the characters in @param allowed_commands. **/
{
    vector<char> allowed_commands = {'q', 'w', 'e', 'd', 'c', 'x', 'z', 'a', 's'};
    for (char attemp : allowed_commands)
    {
        if (tolower(command) == attemp)
            return true;
    }
    return false;
}

bool Game::isAlive() const /** This method verifies if the player is still alive, in other words, it checks if the status of the player correponds to a 'H'. It returns true if so, otherwise, it returns false. **/
{
    return player.getStatus() == 'H';
}

char Game::nextChar(int x, int y) const /** This method returns the status/character of the object which coordinates are @param x and @param y of then maze **/
{
    vector<Portal> portals = maze.getPortals();
    vector<Post> posts = maze.getPosts();
    for (auto robot : robots)
    {
        if (robot.getCord()[0] == x && robot.getCord()[1] == y && robot.getStatus() == 'r')
            return robot.getStatus();
    }
    
    for (auto robot : robots)
    {
        if (robot.getCord()[0] == x && robot.getCord()[1] == y && robot.getStatus() == 'R')
            return robot.getStatus();
    }

    for (auto post : posts) 
    {
        if (post.getCord()[0] == x && post.getCord()[1] == y)
        {
            return post.get_Status();            
        }

    }

    if (player.getCord()[0] == x && player.getCord()[1] == y)
        return player.getStatus();
    for (auto portal : portals)
    {
        if (portal.getCoords()[0] == x && portal.getCoords()[1] == y)
            return 'O';
    }
    return ' ';
}

int Game::player_collide(char button) /** This method verifies if the player collides with other object (with a fence or a robot), returning 0 if it is a valid one, 1 if he/she collided with a non-electrified fence or a stuck robot, 2 if he has collided with a live robot or an electrified, meaning that he/she has lost the game, 3 if he/she finds an exit to escape the maze ('O').**/
{
    button = tolower(button);
    int x = player.getCord()[0];
    int y = player.getCord()[1];

    if (button == 'q' || button == 'w' || button == 'e')
        x--;
    if (button == 'z' || button == 'x' || button == 'c')
        x++;
    if (button == 'q' || button == 'a' || button == 'z')
        y--;
    if (button == 'e' || button == 'd' || button == 'c')
        y++;

    char next_char = nextChar(x, y);

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

void Game::player_moves() /** This method assures the movement of the player, according to the letter typed by the user. The validaty is assured by the player_colllide() function. **/
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
    }
}

void Game::robot_moves() /** This method assures the movement of the robots, according to the movement of the player. It also updates their status in each move, depending on if they had collided with other object (player or fences). **/
{
    for (auto &robot : robots)
    {   
        if (!end() && robot.getStatus() == 'R' && nextChar(robot.getCord()[0], robot.getCord()[1]) == 'R')
        {
            int dist_v, dist_h;

            dist_v = robot.getCord()[0] - player.getCord()[0];

            dist_h = robot.getCord()[1] - player.getCord()[1];

            int new_x = robot.getCord()[0];

            int new_y = robot.getCord()[1];

            if (dist_h > 0 && dist_v == 0)
            {
                new_y--;
            }
            else if (dist_h == 0 && dist_v < 0)
            {
                new_x++;
            }
            else if (dist_h < 0 && dist_v == 0)
            {
                new_y++;
            }
            else if (dist_h == 0 && dist_v > 0)
            {
                new_x--;
            }
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

            if (nextChar(new_x, new_y) == ' ')
            {
                robot.changeCord(new_x,new_y);            
            }
            else if (nextChar(new_x, new_y) == 'R')
            {
                robot.changeCord(new_x,new_y);
                robot.changeStatus('r');
            }       
            else if (nextChar(new_x, new_y) == '*') 
            {
                robot.changeStatus('r');
                maze.changePost(new_x, new_y);
            }
            else if (nextChar(new_x, new_y) == 'H')
            {         
                player.changeStatus();
            }
            else if (nextChar(new_x, new_y) == '+')
            {
                robot.changeCord(new_x,new_y);
                robot.changeStatus('r');
            }
            else if (nextChar(new_x, new_y) == 'O')
            {
                robot.changeCord(new_x,new_y);
            }     
            else
            {
                robot.changeCord(new_x,new_y);
                robot.changeStatus('r');
            }
        }
        else if (nextChar(robot.getCord()[0], robot.getCord()[1]) == 'r')
        {
            robot.changeStatus('r');          
        }
    }
}