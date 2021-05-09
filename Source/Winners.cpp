//Grupo

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Show_winners()
{
    char command;
    bool any_winner = false;
    string winners_file;
    for (int i = 1; i < 100; i++)
    {

        winners_file = i < 10 && i > 0 ? "MAZE_0" + to_string(i) + "_WINNERS.TXT" : "MAZE_" + to_string(i) + "_WINNERS.TXT";
        ifstream file;
        file.open(winners_file);
        if (file.good())
        {
            any_winner = true;
            string line1n2;
            getline(file, line1n2);
            getline(file, line1n2);

            if (!file.eof())
            {
                cout << winners_file.substr(0, 7) + ":" << endl;
                while (!file.eof())
                {
                    string text;
                    getline(file, text);
                    cout << text << endl;
                }
            }
        }
        file.close();
    }
    if (!any_winner)
        cout << "Empty list." << endl;
}