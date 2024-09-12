


#ifndef MOWER_H
#define MOWER_H

#include "common.h"
#include "lawn.h"
#include <random>
#include <time.h>


class Mower {
public:
    Mower(Lawn *lawn);
    Mower();

    Direction   getFacing();
    LawnPos     getPosition();
    SquareType  getSquare();
    Lawn*       getLawn();
    char        getMowerChar();
    int         getPeeks();
    int         getTurns();
    int         getSteps();

    void        setLawn(Lawn *lawn);

    void        turnLeft();
    void        turnRight();
    SquareType  peek();
    bool        forward();
private:
    Lawn        *_lawn;
    Direction   _facing;
    LawnPos     _position;
    int         _peeks;
    int         _turns;
    int         _steps;

    SquareType  checkNextSquare();
};



#endif