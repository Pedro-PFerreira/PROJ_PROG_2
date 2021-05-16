// Grupo

#include "Game.hpp"
#include "Robot.cpp"
#include "Post.hpp"

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

void Game::test()
{
    cout << endl << "Printando a maze:" << endl;
    printMaze();

    cout << endl << "Printando as caracteristicas do Player:" << endl;
    cout << "X = " << player.getCord()[0] << " and Y = " << player.getCord()[1] << endl;
    cout << "Status: " << player.getStatus() << endl;

    cout << endl << "Printando as caracteristicas de cada Post:" << endl;
    vector<Post> all_posts = maze.getPosts();
    for (auto p : all_posts)
    {
        cout << "X = " << p.getCord()[0] << " and Y = " << p.getCord()[1];
        cout << ". Status: " << p.get_Status() << endl;
    }
    
    cout << endl << "Printando as caracteristicas de cada Robot:" << endl;
    for (auto r : robots)
    {
        cout << "X = " << r.getCord()[0] << " and Y = " << r.getCord()[1];
        cout << ". Status: " << r.getStatus() << " and ID = " << r.getID() << endl;
    }
    
}