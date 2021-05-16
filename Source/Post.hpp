//Grupo

#include <vector>

using namespace std;

class Post
{
    public:

    Post();
    void setCord(unsigned int x, unsigned int y);
    void set_Status(char status);
    vector <unsigned int> getCord();
    void change_Status(char status);
    char get_Status();

    private:
    char status;
    unsigned int x;
    unsigned int y;
};

