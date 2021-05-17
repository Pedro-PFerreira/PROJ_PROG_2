//Grupo

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include "Winners.cpp"
#include "Select_maze.cpp"
using namespace std;

void ShowRules()
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

void Menu(bool &want_play, int &number_maze)
{
    int button;

    cout << "Please input an option (type 0,1,2 or 3)" << endl;

    cout << "1) Rules; \n2) Play; \n3) Winners; \n0) Exit." << endl;

    cin >> button;

    if (cin.eof())

        exit(0);

    while (cin.peek() != '\n' || cin.fail() || button < 0 || button > 3)
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
    {
        ShowRules();
        cout << "Press any button to go back to main menu." << endl;
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
    {
        cout << endl;
        Show_winners();
        cout << "Press any button to go back" << endl;
        cin >> button;
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
