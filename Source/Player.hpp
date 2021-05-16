//Grupo

#include <vector>
using namespace std;

class Player 
{
    public:
    Player();
    void setCord (unsigned int x, unsigned int y);
    void setStatus(char status);
    void changeStatus();
    char getStatus();
    void changeCord(unsigned int x, unsigned int y);
    vector<unsigned int> getCord();

    private:
    unsigned int x;
    unsigned int y;
    char status;
};