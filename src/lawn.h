#ifndef LAWN_H
#define LAWN_H

#include "common.h"
#include <random>
#include <time.h>


class Lawn {
public:
    // constructor
    Lawn(int width, int height):
        _width(width),
        _height(height) {
        _field = new Square[width*height];
        initField();
    };
    Lawn();
    // destructor
    ~Lawn() { delete _field; };
    // public functions
    Square  getSquare(int x, int y);
    bool    mowSquare(Position position);
private:
    // private data
    int     _width;
    int     _height;
    Square* _field;

    // helper functions
    void    initField();
};

#endif