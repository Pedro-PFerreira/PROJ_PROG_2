//Grupo

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <limits>

using namespace std;
typedef pair<int, string> record;

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
                cout << endl;
            }
        }
        file.close();
    }
    if (!any_winner)
        cout << "Empty list." << endl;
}

void write_file(int time, int num_maze)
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
        getline(file, header1);
        getline(file, header2);
        
        while (!file.eof())
        {	
            getline(file, current_line);
            winner_name = current_line.substr(0, 15);
            string aux = "";
            for (int i = current_line.find('-') + 1; i < current_line.size() ; i++ )
            {
                aux += current_line[i];
            }
            istringstream str(aux);
            str >> winner_time;
            
            if (winner_time < time && winner_name == name)
            {
                cout << "Uma espécie de mensagem a dizer que já tem um tempo melhor anterior" << endl;
            }
            else if (winner_time >= time && winner_name == name)
            {
                cout << "Significa que está nos records e tem de se atualizar o tempo dele para o mais recente, ou seja, o melhor" << endl;
                winner_time = time;
            }

            record current = make_pair(winner_time, winner_name); 
            all_winners.insert(current);
        }
        file.close();

        ofstream file;
        file.open(file_name);
        file << header1 << endl << header2;

        for (auto winner : all_winners)
                file << endl << winner.second << " - " << winner.first;

        file.close();
    }

    else
    {
		string header = "Player          - Time\n----------------------";
		ofstream file;
        file.open(file_name);
		file << header << endl;
		file << name << " - " << time;
		file.close();
    }
}