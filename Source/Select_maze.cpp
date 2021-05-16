//Grupo

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isFile(int number_maze)
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

void choose_maze(bool &want_play, int &number_maze)
{
    string file_name;
    cout << "Please the number of the maze (type 0 to go back):" << endl;

    cin >> number_maze;
    if (cin.eof())
        exit(0);

    if (number_maze == 0) 
    {
        want_play = false;
    }
    else
    {
        while (cin.fail() || cin.peek() != '\n' || number_maze <0 || number_maze > 99 || !isFile(number_maze))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Maze not found. Please type a valid one." << endl;
            cout << "Please input the number of the maze (type 0 to go back):" << endl;
            cin >> number_maze;
            if (cin.eof())
                exit(0);
            if (number_maze == 0) 
            {
                break;
            }

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
}
