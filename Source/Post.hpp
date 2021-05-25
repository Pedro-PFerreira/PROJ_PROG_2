//T04_G04

#ifndef POST_DEFINED
#define POST_DEFINED

class Post // The class Post ensures the creation of the maze's posts. In the "Post.cpp" explains how each method works.
{
    public:
    Post();
    void setCord(int x, int y);
    void set_Status(char status);
    void change_Status();
    char get_Status() const;
    vector <int> getCord() const;

    private:
    char status;
    int x;
    int y;
};

#endif