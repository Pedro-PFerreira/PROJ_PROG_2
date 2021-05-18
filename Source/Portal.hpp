//Grupo

#ifndef PORTAL_DEFINED
#define PORTAL_DEFINED

class Portal
{
    public:
    Portal();
    void setCord (unsigned int x, unsigned int y);
    vector<unsigned int> getCoords() const;

    private:
    unsigned int x;
    unsigned int y;

};

#endif