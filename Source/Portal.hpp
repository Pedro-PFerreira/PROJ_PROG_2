//Grupo

#ifndef PORTAL_DEFINED
#define PORTAL_DEFINED

#include <vector>


class Portal
{
    public:
    Portal();
    void setCord (unsigned int x, unsigned int y);
    vector<unsigned int> getCoords();

    private:
    unsigned int x;
    unsigned int y;
};

#endif