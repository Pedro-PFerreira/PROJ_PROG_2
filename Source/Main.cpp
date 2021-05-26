//T04_G04

#include <iostream>
#include <vector>
#include <set>
#include <iostream>
#include <limits>
#include <ctime>

#include "Show_Menu.cpp"
#include "Maze.cpp"
#include "Game.cpp"
#include "Player.cpp"
#include "Robot.cpp"

using namespace std;

int main() //The main function assures the execution of the game.
{
    srand(time(NULL));
    bool want_play = false; //This flag indicates if the user wants to play - it becomes true when he/she chooses a maze.
    bool play_again = true; //This flag indicates if the user wants to play again - it becomes true when the user types 'y' or 'Y' at the end of the game (lines 55-80).
    int number_maze, time1, time2; /** @param number_maze - number of the chosen maze; @param time1- initial time, that is, when the user starts playing; @param time2 - final time, that is, time when the user completes sucessfully the maze.**/

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
            game.player_moves();
            game.printMaze();
        }
        time2 = time(NULL);

        if (game.isAlive()) //win condition
        {
            cout << "Congratulations, you won!" << endl;
            write_file(time2 - time1, number_maze);
        }

        else
        {
            cout << "You lost!" << endl;
        }

        char ans;
        cout << "Do you want to play again (y/n)?" << endl; // The player can play again if he/she wants and, if so, the main menu will be shown again.

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