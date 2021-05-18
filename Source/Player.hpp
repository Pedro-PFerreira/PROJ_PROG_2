//Grupo

#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

// The class Player ensures the good functionality of the player during the game. In the "Player.cpp" explains how each function works.**/

class Player 
{
    public:
    Player();
    void setCord (unsigned int x, unsigned int y);
    void changeCord(unsigned int x, unsigned int y);
    void setStatus(char status);
    void changeStatus();
    void changeWin();
    char getStatus() const;
    bool Win() const;
    vector<unsigned int> getCord() const;

    private:
    unsigned int x;
    unsigned int y;
    char status;
    bool win;
};

#endif