


#ifndef MOWER_H
#define MOWER_H

#include "common.h"
#include "lawn.h"
#include <random>
#include <time.h>


class Mower {
public:
    // constructor
    Mower(Lawn *lawn);

    // getters
    Direction getFacing();
    Position getPosition();
    Lawn* getLawn();
    char getMowerChar();
    int getPeeks();
    int getTurns();
    int getSteps();

    // setter
    void setLawn(Lawn *lawn);

    // mower actions
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

    Square checkNextSquare();
};



#endif