//Grupo

#ifndef POST_DEFINED
#define POST_DEFINED

class Post // The class Post ensures the creation of the maze's posts. In the "Player.cpp" explains how each method works.
{
    public:
    Post();
    void setCord(unsigned int x, unsigned int y);
    void set_Status(char status);
    void change_Status();
    char get_Status() const;
    vector <unsigned int> getCord() const;

    private:
    char status;
    unsigned int x;
    unsigned int y;
};

#endif