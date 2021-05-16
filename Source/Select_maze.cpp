//Grupo

#include <iostream>
#include <string>

using namespace std;

// File name!!!!!!!!!!!!!!!!!!!!!--->>>> Important!!!!!

void choose_maze(bool &want_play, int &number_maze)
{
    string file_name;
    cout << "Please the number of the maze (type 0 to go back):" << endl;

    cin >> number_maze;
    if (cin.eof())
        exit(0);

    while (cin.fail() || cin.peek() != '\n' || number_maze <0 || number_maze > 99)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid number. Please type a valid one." << endl;
        cout << "Please the number of the maze (type 0 to go back):" << endl;
        cin >> number_maze;
        if (cin.eof())
            exit(0);

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
