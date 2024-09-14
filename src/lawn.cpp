
#include "lawn.h"

/***** CONSTRUCTORS/DESTRUCTORS *****/

// Construct new Lawn object with width and height specified
Lawn::Lawn(int width, int height):
    _width(width),
    _height(height)  {
    // create a field matrix as an array
    _field = new Square[_width * _height];
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
    _field = new Square[_width * _height];
    // initialize field
    initField();
}

// delete _field pointer upon object destruction
Lawn::~Lawn() { delete _field; }

/***** GETTERS/ACCESSORS *****/

// Return lawn width
int Lawn::getWidth() const { return _width; }

// Return lawn height
int Lawn::getHeight() const { return _height; }

// Return Square at position
Square Lawn::getSquare(LawnPos position) const {
    int x_index = position.getX();
    int y_index = _height - position.getY() - 1;
    return _field[(y_index * _width) + x_index];
}

/***** PUBLIC FUNCTIONS *****/

// Cause an unmowed Square at position to become mowed
// Ignores wall Squares
bool Lawn::mowSquare(LawnPos position) {
    int x_index = position.getX();
    int y_index = _height - position.getY() - 1;
    if (_field[(y_index * _width) + x_index].getType() != SquareType::wall) {
        _field[(y_index * _width) + x_index].setType(SquareType::mowed);
        return true;
    }
    return false;       // can't mow the wall
}

/***** PRIVATE HELPER FUNCTIONS *****/

void Lawn::initField() {

    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            if (y == 0 || y == _height - 1) {
                _field[(y * _width) + x].setType(SquareType::wall);
                _field[(y * _width) + x].setVariant(0);
            } else if (x == 0) {
                _field[(y * _width) + x].setType(SquareType::wall);
                _field[(y * _width) + x].setVariant(1);
            } else if (x == _width - 1) {
                _field[(y * _width) + x].setType(SquareType::wall);
                _field[(y * _width) + x].setVariant(2);
            } else
                _field[(y * _width) + x].setType(SquareType::unmowed);
        } // end column loop
    } // end row loop
}
