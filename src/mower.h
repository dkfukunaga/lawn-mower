


#ifndef MOWER_H
#define MOWER_H

#include "lawn.h"
#include "lawnPos.h"
#include "direction.h"
#include <random>
#include <time.h>


struct Mower {
    Lawn*       lawn;
    Direction   facing;
    LawnPos     lawn_pos;
    int         peeks;
    int         turns;
    int         steps;

    Mower();
    Mower(Lawn *new_lawn);

    SquareType  peek();
    bool        forward();
    void        turnLeft();
    void        turnRight();

    int         getTotal() const;
    void        reset();
};



#endif