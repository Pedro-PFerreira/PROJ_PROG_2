//T04_G04

#ifndef ROBOT_DEFINED
#define ROBOT_DEFINED

class Robot // The class Robot ensures the good functionality of the player during the game. In the "Robot.cpp" explains how each method works.
{
    public:
    Robot();
    void setCord (int x, int y);
    void changeCord(int x, int y);
    void setStatus(char status);
    void changeStatus(char s);
    char getStatus() const;
    int getID() const;
    vector<int > getCord();

    private:
    int x;
    int y;
    int id;
    static int numRobots;
    char status;
};

#endif