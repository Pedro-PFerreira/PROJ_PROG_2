//Grupo

#ifndef POST_DEFINED
#define POST_DEFINED


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

#endif