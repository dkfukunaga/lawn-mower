
#include "position.h"


/***** CONSTRUCTORS *****/

Position::Position(int x = 0, int y = 0):
    _x(x),
    _y(y) { };

Position::Position(const Position &that):
    _x(that.getX()),
    _y(that.getY()) { };

/***** GETTERS/ACCESSORS *****/

int Position::getX() const { return _x; }

int Position::getY() const { return _y; }

/***** SETTERS/MUTATORS *****/

void Position::set(int x, int y) {
    _x = x;
    _y = y;
}

void Position::move(int x, int y) {
    _x += x;
    _y += y;
}

/***** OPERATOR OVERRIDES *****/


bool Position::operator==(Position &rhs) {
    return this->_x == rhs._x && this->_y == rhs._y;
}

bool Position::operator!=(Position &rhs) {
    return !(*this == rhs);
}