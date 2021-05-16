//Grupo

#ifndef ROBOT_DEFINED
#define ROBOT_DEFINED


#include <vector>
using namespace std;

class Robot 
{
    public:
    Robot();
    void setCord (unsigned int x, unsigned int y);
    void setStatus(char status);
    void setID(unsigned int id);
    void changeStatus();
    char getStatus();
    unsigned int getID();
    void changeCord(unsigned int x, unsigned int y);
    vector<unsigned int> getCord();

    private:
    unsigned int x;
    unsigned int y;
    unsigned int id;
    char status;
};

#endif