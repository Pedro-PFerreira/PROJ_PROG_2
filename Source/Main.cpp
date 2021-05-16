//Grupo

#include <iostream>
#include "Show_Menu.cpp"
#include "Post.cpp"
#include "Player.cpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    bool want_play = false;

    while (!want_play)
    {
        Menu(want_play);
    }


    return 0;
}