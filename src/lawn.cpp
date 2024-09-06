

#include "lawn.h"

Square Lawn::getSquare(int x, int y) {
    return _field[(y * _width) + x - 2];
}

bool Lawn::mowSquare(int x, int y) {
    if (_field[(y * _width) + x - 2] != Square::wall) {
        _field[(y * _width) + x - 2] = Square::mowed;
        return true;
    }
    return false;       // can't mow the wall
}

void Lawn::initField() {
    // int x = 0;
    // int y = 0;

    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            if ((y == 0 || y == _height - 1) || 
                (x == 0 || x == _width - 1))
                _field[(y * _width) + x] == Square::wall;
            else
                _field[(y * _width) + x] == Square::unmowed;
        }
    }
}