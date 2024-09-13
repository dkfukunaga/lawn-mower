
#include "position.h"


/***** CONSTRUCTORS *****/

// Default constructor for Position
// defaults coordinates to (0, 0)
Position::Position():
    _x(0),
    _y(0) { };

// Constructor for Position
Position::Position(int x, int y):
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

// move once in direction
// north (y + 1), west (x - 1), south (y - 1), east (x + 1)
// returns new Position
Position Position::move(Direction direction) {
    switch (direction) {
        case Direction::north:
            move(0, 1);
            break;
        case Direction::west:
            move(-1, 0);
            break;
        case Direction::south:
            move(0, -1);
            break;
        case Direction::east:
            move(1, 0);
            break;
    }
    return *this;
}

// move north (y + 1) once
// returns new Position
Position Position::north() const {
    return Position(_x, _y + 1);
}

// move west (x - 1) once
// returns new Position
Position Position::west() const {
    return Position(_x - 1, _y);
}

// move south (y - 1) once
// returns new Position
Position Position::south() const {
    return Position(_x, _y - 1);
}

// move east (x + 1) once
// returns new Position
Position Position::east() const {
    return Position(_x + 1, _y);
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