


#ifndef MOWER_H
#define MOWER_H

#include "lawn.h"
#include "position.h"
#include <random>
#include <time.h>


class Mower {
public:
    Mower(Lawn *lawn);
    Mower();
    ~Mower();

    Direction   getFacing() const;
    LawnPos     getLawnPos() const;
    Square      getSquare() const;
    Lawn*       getLawn() const;
    char        getMowerChar() const;
    int         getPeeks() const;
    int         getTurns() const;
    int         getSteps() const;
    int         getTotal() const;

    void        setLawn(Lawn *lawn);

    void        turnLeft();
    void        turnRight();
    SquareType  peek();
    bool        forward();
private:
    Lawn        *_lawn;
    Direction   _facing;
    LawnPos     _lawn_pos;
    int         _peeks;
    int         _turns;
    int         _steps;

    SquareType  checkNextSquare();
};



#endif