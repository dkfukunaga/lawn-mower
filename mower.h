


#ifndef MOWER_H
#define MOWER_H

#include "common.h"
#include "lawn.h"
#include <random>
#include <time.h>


class Mower {
public:
    Mower();

    Direction getFacing();
    Position getPosition();
    int getPeeks();
    int getTurns();
    int getSteps();
    char getMowerChar();
    void turnLeft();
    void turnRight();
    Square peek();
    bool forward();
private:
    Lawn *_lawn;
    Direction _facing;
    Position _position;
    int _peeks;
    int _turns;
    int _steps;

    bool canMove();
};



#endif