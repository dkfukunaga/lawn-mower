

#include "lawn.h"
#include <random>
#include <time.h>

// Construct new Lawn object with randomized width and height
// currently set to 15 ~ 22.
Lawn::Lawn() {
    srand(time(NULL));

    Lawn(rand() % 15 + 7, rand() % 15 + 7);
}

// Return Square at position
Square Lawn::getSquare(Position position) {
    return _field[(position.y * _width) + position.x - 2];
}

// Cause an unmowed Square at position to become mowed
// Ignores wall Squares
bool Lawn::mowSquare(Position position) {
    if (_field[(position.y * _width) + position.x - 2] != Square::wall) {
        _field[(position.y * _width) + position.x - 2] = Square::mowed;
        return true;
    }
    return false;       // can't mow the wall
}

// Initialize Lawn with a wall all around the border and
// unmowed Squares everywhere else
void Lawn::initField() {
    // int x = 0;
    // int y = 0;

    // loop through rows
    for (int y = 0; y < _height; y++) {
        // loop through columns
        for (int x = 0; x < _width; x++) {
            // calculate index from x,y
            if ((y == 0 || y == _height - 1) || 
                (x == 0 || x == _width - 1))
                _field[(y * _width) + x] == Square::wall;
            else
                _field[(y * _width) + x] == Square::unmowed;
        }
    }
}


// TODO:
// add support for specific lawn size,
//   and/or min/max range for randomization
// override bracket operators