//Grupo

#ifndef ROBOT_DEFINED
#define ROBOT_DEFINED

class Robot 
{
    public:
    Robot();
    void setCord (unsigned int x, unsigned int y);
    void changeCord(unsigned int x, unsigned int y);
    void setStatus(char status);
    void setID(unsigned int id);
    void changeStatus(char s);
    char getStatus() const;
    unsigned int getID() const;
    vector<unsigned int> getCord();

    private:
    unsigned int x;
    unsigned int y;
    unsigned int id;
    char status;
};

#endif