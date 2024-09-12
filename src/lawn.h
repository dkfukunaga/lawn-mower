#ifndef LAWN_H
#define LAWN_H

#include "common.h"
#include "square.h"
#include <random>
#include <time.h>

// A rectangle of Squares with a one square wide border
// of wall Squares and either unmowed or mowed Squares
// inside the border
class Lawn {
public:
    Lawn(int width, int height);
    Lawn();
    ~Lawn() { delete _field; };

    int         getWidth();
    int         getHeight();

    SquareType  getSquare(LawnPos position);
    bool        mowSquare(LawnPos position);
private:
    int         _width;
    int         _height;
    Square*     _field;

    void        initField();
};

#endif