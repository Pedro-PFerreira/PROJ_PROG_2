//T04_G04

#include "Player.hpp"

Player::Player() /** This method is the constructor of the class Player. **/
{
    x = 0;
    y = 0;
    status = 'H';
    win = false;
}

void Player::setCord (int x, int y) /** This method will define the player's coordinates on the maze, according the @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

void Player::setStatus(char status) /** This method will define the player's status, according to @param status ('h' or 'H') **/
{
    this -> status = status;
}

void Player::changeStatus() /** This method changes the player's status to 'h'. This method will be called when the player collide with a live robot or an electrified fence. **/
{
    status = 'h';
}

void Player::changeCord(int x, int y) /** This method modifies the player's coordinates, by replacing the current values to the values of @param x and @param y. **/
{
    this -> x = x;
    this -> y = y;
}

vector<int> Player::getCord() const /** This method returns a vector @param coord which contains the current coordinates of the player. **/
{
    vector<int> coord = {};
    coord.push_back(x);
    coord.push_back(y);
    return coord;
}

char Player::getStatus() const /** This method returns the current status of the player. **/
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