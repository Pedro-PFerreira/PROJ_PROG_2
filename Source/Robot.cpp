//T04_G04

#include "Robot.hpp"
unsigned int Robot::numRobots = 0; /** Initialization of the static member of the Robot class, which is responsible for making an id automatically **/

Robot::Robot() /** This method is the constructor of the class Robot. **/
{
    x = 0;
    y = 0;
    status = 'R';
    numRobots++;
    id = numRobots;
}

void Robot::setCord (unsigned int x, unsigned int y) /** This method will define the robot's coordinates on the maze, according the @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

void Robot::setStatus(char status) /** This method will define the robot's status, according to @param status ('r' or 'R') **/
{
    this -> status = status;
}

void Robot::setID(unsigned int id) /** This method will define the robot's ID, according to @param id that will determine which robot will move first after the move of the player during the game. **/
{
    this -> id = id;
}

void Robot::changeStatus(char s) /** This method chnages the robot's status to 'r'. This method will be called when the robot collide with a live/stuck robot or an (non-) electrified fence. **/
{
    status = s;
}

void Robot::changeCord(unsigned int x, unsigned int y) /** This method modifies the robot's coordinates, by replacing the current values to the values of @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Robot::getCord() /** This method returns a vector @param coord which contains the current coordinates of the robot. **/
{
    vector<unsigned int> coord = {};
    coord.push_back(x);
    coord.push_back(y);
    return coord;
}

char Robot::getStatus() const /** This method returns the current status of the robot. **/
{
    return status;
}

unsigned int Robot::getID() const /** This method returns the ID number of the robot. **/
{
    return id;
}