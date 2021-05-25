//T04_G04

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <limits>

using namespace std;
typedef pair<int, string> record;

void Show_winners() /** This function shows all the winners of each maze on console, in case if they exist. If so, shows by ascending order the winners with the best times, otherwise it shows "Empty list." on the screen **/
{
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
                cout << endl;
            }
        }
        file.close();
    }
    if (!any_winner)
        cout << "Empty list." << endl;
}

void write_file(int time, int num_maze) /** This function writes to the record's file the new name of the user and the time spent to complete the maze, in case he/she has completed the maze succesfully. If the record's file of the maze played by the user already exists, it simplty adds the name and the time on file, if he/she did a better time than before, or only warns the user that a better time already exists, if so; otherwise it creates a new file, adding the player's maze and the time to it. **/
{
    set <record> all_winners;
    string name, file_name, current_line, header1, header2, winner_name;
    int winner_time;

	cout << "Input your name: ";
	getline(cin, name);

	if (cin.eof())
		exit(0);

	while (name.size() > 15 || !name.size())
	{
	    if (name.size() > 15)
            cerr << "Its too long. Please input a shorter name: " << endl;
		getline(cin, name);
		if (cin.eof())
			exit(0);
	}

    while (name.size() < 15)
    {
        name += ' ';
    }

    file_name = num_maze < 10 && num_maze > 0 ? "MAZE_0" + to_string(num_maze) + "_WINNERS.TXT" : "MAZE_" + to_string(num_maze) + "_WINNERS.TXT";
    ifstream file;
    file.open(file_name);

    if (file.good())
    {   
        bool new_record = true;
        getline(file, header1);
        getline(file, header2);
        
        while (!file.eof())
        {	
            getline(file, current_line);
            winner_name = current_line.substr(0, 15);
            string aux = "";
            for (long long unsigned int i = current_line.find('-') + 1; i < current_line.size() ; i++ )
            {
                aux += current_line[i];
            }
            istringstream str(aux);
            str >> winner_time;
            
            if (winner_time < time && winner_name == name)
            {
                cout << "New record, congratulations!" << endl;
                new_record = false;
            }
            else if (winner_time >= time && winner_name == name)
            {
                cout << "A better time already exists." << endl;
                winner_time = time;
                new_record = false;
            }

            record current = make_pair(winner_time, winner_name); 
            all_winners.insert(current);
        }
        file.close();

        if (new_record)
        {
            record new_winner = make_pair(time, name);
            all_winners.insert(new_winner);
        }

        ofstream file;
        file.open(file_name);
        file << header1 << endl << header2;

        for (auto winner : all_winners)
                file << endl << winner.second << " - " << winner.first;

        file.close();
    }

    else // If the Record's file of the maze played hasn't been created yet, it will be creted a new file, with the corresponding name of the maze, writing to it the header of the file, the player's name and also the time spent to complete the maze successfully.
    {
		string header = "Player          - Time\n----------------------";
		ofstream file;
        file.open(file_name);
		file << header << endl;
		file << name << " - " << time;
		file.close();
    }
}