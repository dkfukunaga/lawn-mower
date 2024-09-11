
#include "common.h"
#include "lawn.h"
#include <random>
#include <time.h>
#include <iostream>

// Construct new Lawn object with width and height specified
Lawn::Lawn(int width, int height):
    _width(width),
    _height(height)  {
    // create a field matrix as an array
    _field = new Square[width * height];
    // initialize field
    initField();
};

// Construct new Lawn object with randomized width and height
// currently set to 7 ~ 22.
Lawn::Lawn() {
    srand(time(NULL));
    Lawn(rand() % 15 + 7, rand() % 15 + 7);
}

// Return Square at position
Square Lawn::getSquare(Position position) {
    return _field[(position.y * _width) + position.x];
}

// Cause an unmowed Square at position to become mowed
// Ignores wall Squares
bool Lawn::mowSquare(Position position) {
    if (_field[(position.y * _width) + position.x] != Square::wall) {
        _field[(position.y * _width) + position.x] = Square::mowed;
        return true;
    }
    return false;       // can't mow the wall
}

// Initialize Lawn with a wall all around the border and
// unmowed Squares everywhere else
void Lawn::initField() {

    // loop through rows
    for (int y = 0; y < _height; y++) {
        // loop through columns
        for (int x = 0; x < _width; x++) {
            // calculate index from x,y
            if ((y == 0 || y == _height - 1) || 
                (x == 0 || x == _width - 1))
                _field[(y * _width) + x] = Square::wall;
            else
                _field[(y * _width) + x] = Square::unmowed;
        } // end column loop
    } // end row loop
}


// TODO:
// add support for specific lawn size,
//   and/or min/max range for randomization
// override bracket operators