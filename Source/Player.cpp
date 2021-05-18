//Grupo
// Methods of the class Player.

#include "Player.hpp"

Player::Player() /** This method is the constructor of the class. **/
{
    x = x;
    y = y;
    status = status;
    win = false;
}

void Player::setCord (unsigned int x, unsigned int y) /** This method will define the player's coordinates on the maze, according the @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

void Player::setStatus(char status) /** This method will define the player's status, according to @param status ('h' or 'H') **/
{
    this -> status = status;
}

void Player::changeStatus() /** This method chnages the player's status to 'h'. This method will be called when the player collide with a live robot or an electrified fence. **/
{
    status = 'h';
}

void Player::changeCord(unsigned int x, unsigned int y) /** This method modifies the player's coordinates, by replacing the current values to the values of @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

vector<unsigned int> Player::getCord() const /** This method returns a vector which contains the current corrdinates of the player. **/
{
    vector<unsigned int> coord = {};
    coord.push_back(x);
    coord.push_back(y);
    return coord;
}

char Player::getStatus() const /** This method returns the current status player. **/
{
    return status;
}

void Player::changeWin() /** This method turns the flag @param win to true, in case the player has completed the maze succesfully. **/
{
    win = true;
}

bool Player::Win() const // This method verifies if the player has won the game, by returning the value @param win: it returns true if so, otherwise it returns false.
{
    return win;
}