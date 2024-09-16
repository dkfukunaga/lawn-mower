
#include "position.h"


/***** CONSTRUCTORS *****/

// Default constructor for Position
// defaults coordinates to (0, 0)
Position::Position():
    x(0),
    y(0) { }

// Constructor for Position
Position::Position(int new_x, int new_y):
    x(new_x),
    y(new_y) { }

// Copy constructor
Position::Position(const Position &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
}

/***** FUNCTIONS *****/

// returns true if coordinates are both non-negative
// returns false otherwise
bool Position::good() { return x >= 0 && y >= 0; }


// Sets Position to new x,y coordinates
// Checks for valid (non-negative) values. If invalid, does nothing.
//
// returns possibly updated Position
Position Position::set(int new_x, int new_y) {
    if (new_x > 0 && new_y > 0) {
        x = new_x;
        y = new_y;
    }
    return *this;
}

// Sets Position to new x,y coordinates from another Position object.
// Checks for valid (non-negative) values. If invalid, does nothing.
//
// returns possibly updated Position
Position Position::set(Position pos) {
    if (pos.good()) {
        x = pos.x;
        y = pos.y;
    }
    return *this;
}

/***** OPERATOR OVERRIDES *****/

// assigns new position
Position& Position::operator=(const Position &rhs) {
    if (this != &rhs) {
        x = rhs.x;
        y = rhs.y;
    }
    return *this;
}

// returns true if x and y are the same, false otherwise
bool Position::operator==(const Position &rhs) {
    return this->x == rhs.x && this->y == rhs.y;
}

// returns true if x or y are different, false otherwise
bool Position::operator!=(const Position &rhs) {
    return !(*this == rhs);
}



