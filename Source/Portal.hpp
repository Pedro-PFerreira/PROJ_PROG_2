//T04_G04

#ifndef PORTAL_DEFINED
#define PORTAL_DEFINED

class Portal // The class Post ensures the creation of the maze's portals. In the "Portal.cpp" explains how each method works.
{
    public:
    Portal();
    void setCord (int x, int y);
    vector<int> getCoords() const;

    private:
    unsigned int x;
    unsigned int y;

};

#endif