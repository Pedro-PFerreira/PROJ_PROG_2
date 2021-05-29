//T04_G04

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include "Winners.cpp"
#include "Select_maze.cpp"
using namespace std;

void ShowRules() /** This function shows on the screen the content of the file RULES.TXT **/
{

    ifstream file;
    file.open("RULES.TXT");
    if (file.good())
    {
        while (!file.eof())
        {
            string text;
            getline(file, text);
            cout << text << endl;
        }
    }

    file.close();
}

void Menu(bool &want_play, int &number_maze) /** This function secures the functionality of the menu, according to the commands inputed by the user: if he/she types 0, the game finishes its execution, if he/she types 1, the game's rules are shown on the screen; if it was typed 2, the player will choose the maze to play, if is was inputed 3, the winners of each maze will be shown on the screen. **/
{
    int button;

    cout << "Please input an option (type 0,1,2 or 3)" << endl;

    cout << "1) Rules; \n2) Play; \n3) Winners; \n0) Exit." << endl;

    cin >> button;

    if (cin.eof())

        exit(0);

    while (cin.fail() || cin.peek() != '\n' || button < 0 || button > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Error, please try again." << endl;
        cout << "Please input an option (type 0,1,2 or 3)" << endl;
        cout << "1) Rules; \n2) Play; \n3) Winners; \n0) Exit." << endl;
        cin >> button;
        if (cin.eof())
        {
            exit(0);
        }
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (button == 1)
    {   string aux;
        ShowRules();
        cout << "Press any button to go back to main menu." << endl;
        cin >> aux;
        if (cin.eof())
        {
            exit(0);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin)

            want_play = false;
    }
    else if (button == 2)
    {
        choose_maze(want_play, number_maze);
    }

    else if (button == 0)
        exit(0);

    else if (button == 3)
    {   string temp;
        Show_winners();
        cout << "Press any button to go back to main menu." << endl;
        cin >> temp;
        if (cin.eof())
        {
            exit(0);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin)

            want_play = false;
    }

    else
        exit(0);
}
