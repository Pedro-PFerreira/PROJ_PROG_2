//Grupo

#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

#include <vector>

class Player 
{
    public:
    Player();
    void setCord (unsigned int x, unsigned int y);
    void setStatus(char status);
    void changeWin();
    void changeStatus(char status);
    char getStatus();
    void changeCord(unsigned int x, unsigned int y);
    bool Win();
    vector<unsigned int> getCord();

    private:
    unsigned int x;
    unsigned int y;
    char status;
    bool win;
};

#endif