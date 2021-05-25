//T04_G04

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isFile(int number_maze) // This function validates if the maze chosen by the user is exist or not- it return true if so, othwerwise it returns false.
{
    string name_maze = number_maze < 10 && number_maze > 0 ? "MAZE_0" + to_string(number_maze) + ".TXT" : "MAZE_" + to_string(number_maze) + ".TXT";
    ifstream file;
    file.open(name_maze);
    if (file.good())
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}

void choose_maze(bool &want_play, int &number_maze) //This function ensures the smooth run of the game during the selection of the maze to play: the user must type a number between 1 and 99. Whether the maze doesn't exist or the user does not type a valid number (a string, a number higher than 99 or lower than 0, for example), an error message will be shown on the screen, and the user will be asked to input a valid number.

{
    bool flag = true;
    string file_name;
    cout << "Please the number of the maze (type 0 to go back):" << endl;
    cin >> number_maze;
    if (cin.eof())
        exit(0);
    while (flag)
    {   if (cin.eof())
            exit(0);
        if (cin.fail() || cin.peek() != '\n' || number_maze < 0 || number_maze > 99)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Maze not found. Please type a valid one." << endl;
            cout << "Please input the number of the maze (type 0 to go back):" << endl;
            cin >> number_maze;
        }
        else if (number_maze == 0)
            break;

        else if (!isFile(number_maze))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Maze not found. Please type a valid one." << endl;
            cout << "Please input the number of the maze (type 0 to go back):" << endl;
            cin >> number_maze;
        }
        else
            flag = false;
    }
    if (number_maze == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        want_play = false;
    }
    else
    {
        want_play = true;
    }
}