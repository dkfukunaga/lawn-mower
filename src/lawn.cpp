
#include "common.h"
#include "lawn.h"
#include <random>
#include <time.h>

// Construct new Lawn object with width and height specified
Lawn::Lawn(int width, int height):
    _width(width),
    _height(height)  {
    // create a field matrix as an array
    _field = new SquareType[_width * _height];
    // initialize field
    initField();
};

// Construct new Lawn object with randomized width and height
// currently set to 7 ~ 22.
Lawn::Lawn() {
    // set width and height to random values from 7 ~ 22
    srand(time(NULL));
    _width = rand() % 15 + 7;
    _height = rand() % 15 + 7;

    // create a field matrix as an array
    _field = new SquareType[_width * _height];
    // initialize field
    initField();
}

// Return lawn width
int Lawn::getWidth() { return _width; }

// Return lawn height
int Lawn::getHeight() { return _height; }

// Return Square at position
SquareType Lawn::getSquare(Position position) {
    int x_index = _width - position.x - 1;
    int y_index = _height - position.y - 1;
    return _field[(y_index * _width) + x_index];
}

// Cause an unmowed Square at position to become mowed
// Ignores wall Squares
bool Lawn::mowSquare(Position position) {
    int x_index = _width - position.x - 1;
    int y_index = _height - position.y - 1;
    if (_field[(y_index * _width) + x_index] != SquareType::wall) {
        _field[(y_index * _width) + x_index] = SquareType::mowed;
        return true;
    }
    return false;       // can't mow the wall
}

void Lawn::initField() {

    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            if ((y == 0 || y == _height - 1) || 
                (x == 0 || x == _width - 1))
                _field[(y * _width) + x] = SquareType::wall;
            else
                _field[(y * _width) + x] = SquareType::unmowed;
        } // end column loop
    } // end row loop
}


// TODO:
// add support for specific lawn size,
//   and/or min/max range for randomization
// override bracket operators