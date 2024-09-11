#ifndef LAWN_H
#define LAWN_H

#include "common.h"

enum class Square {
    wall,       // red
    unmowed,    // green
    mowed       // green
};

// A rectangle of Squares with a one square wide border
// of wall Squares and either unmowed or mowed Squares
// inside the border
class Lawn {
public:
    Lawn(int width, int height);
    Lawn();
    ~Lawn() { delete _field; };
    
    Square  getSquare(Position position);
    bool    mowSquare(Position position);
private:
    int     _width;
    int     _height;
    Square* _field;

    void    initField();
};

#endif