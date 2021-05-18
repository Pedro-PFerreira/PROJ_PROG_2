//Grupo

#include <iostream>
#include <vector>
#include <iostream>
#include <limits>
#include <ctime>
#include "Show_Menu.cpp"
#include "Maze.cpp"
#include "Game.cpp"
#include "Player.cpp"

using namespace std;

int main()
{
    srand(time(NULL));
    bool want_play = false;
    bool play_again = true;
    int number_maze, time1, time2;

    while (play_again)
    {
        while (!want_play)
        {
            Menu(want_play, number_maze);
        }

        Game game;
        game.createObjects(number_maze);

        time1 = time(NULL);
        while (!game.end())
        {   
            game.printMaze();
            game.player_moves();
        }
        game.printMaze();
        time2 = time(NULL);

        if (game.isAlive())
        {
            cout << "Congratulations, you won!" << endl;
            write_file(time2 - time1, number_maze);
        }

        else
        {
            cout << "You lost!";
        }

        char ans;
        cout << "Do you want to play again (y/n)?" << endl;

        cin >> ans;
        if (cin.eof())
		{
			exit(0);
		}
		while ((tolower(ans) != 'y' && tolower(ans) != 'n') || cin.peek() != '\n') /** If it is not inputed an 'y' or a 'n', it will appear an error message and the user will be asked to input a valid charater.**/
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid button, please input a valid button: ";
			cin >> ans;
			if (cin.eof())
			{
				exit(0);
			}
		}

		if (tolower(ans) == 'y')
        {
			play_again = true;  
            want_play = false;          
        }
		else
			play_again = false;
    }

    return 0;
}