
#include "position.h"


/***** CONSTRUCTORS *****/

// Constructor for Position
// defaults coordinates to (0, 0)
Position::Position(int x = 0, int y = 0):
    _x(x),
    _y(y) { };

// Copy constructor
Position::Position(const Position &that):
    _x(that.getX()),
    _y(that.getY()) { };

/***** GETTERS/ACCESSORS *****/

// returns x coordinate
int Position::getX() const { return _x; }

// returns y coordinate
int Position::getY() const { return _y; }

/***** SETTERS/MUTATORS *****/

// sets x and y coordinates to new values
// returns new position
Position Position::set(int x, int y) {
    _x = x;
    _y = y;
    return *this;
}

// moves x and y coordinates by offset
// returns new position
Position Position::move(int x, int y) {
    _x += x;
    _y += y;
    return *this;
}

/***** OPERATOR OVERRIDES *****/

// returns true if x and y are the same, false otherwise
bool Position::operator==(Position &rhs) {
    return this->_x == rhs._x && this->_y == rhs._y;
}

// returns true if x or y are different, false otherwise
bool Position::operator!=(Position &rhs) {
    return !(*this == rhs);
}