//T04_G04

#ifndef PLAYER_DEFINED
#define PLAYER_DEFINED

// The class Player ensures the good functionality of the player during the game. In the "Player.cpp" explains how each method works.

class Player 
{
    public:
    Player();
    void setCord (int x, int y);
    void changeCord(int x, int y);
    void setStatus(char status);
    void changeStatus();
    void changeWin();
    char getStatus() const;
    bool Win() const;
    vector<int> getCord() const;

    private:
    int x;
    int y;
    char status;
    bool win;
};

#endif