

#include "lawnPos.h"


LawnPos::LawnPos(): Position(0,0) { }

LawnPos::LawnPos(int new_x, int new_y): Position(new_x, new_y) { }

LawnPos::LawnPos(const LawnPos &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
}

// Sets LawnPos to new x,y coordinates
// Checks for valid (non-negative) values. If invalid, does nothing.
//
// returns possibly updated LawnPos
LawnPos LawnPos::set(int new_x, int new_y) {
    if (new_x > 0 && new_y > 0) {
        x = new_x;
        y = new_y;
    }
    return *this;
}

// Sets lawnPos to new x,y coordinates from another LawnPos
// Checks for valid (non-negative) values. If invalid, does nothing.
//
// returns possibly updated LawnPos
LawnPos LawnPos::set(LawnPos lawn_pos) {
    if (lawn_pos.good()) {
        x = lawn_pos.x;
        y = lawn_pos.y;
    }
    return *this;
}

LawnPos LawnPos::move(Direction direction) {
    switch (direction) {
        case Direction::north:
            y++;
            break;
        case Direction::west:
            x--;
            break;
        case Direction::south:
            y--;
            break;
        case Direction::east:
            x++;
            break;
    }
    return *this;
}

// returns lawn position to the north (y + 1)
LawnPos LawnPos::north() const {
    return LawnPos(x, y + 1);
}

// returns lawn position to the west (x - 1)
LawnPos LawnPos::west() const {
    return LawnPos(x - 1, y);
}

// returns lawn position to the south (y - 1)
LawnPos LawnPos::south() const {
    return LawnPos(x, y - 1);
}

// returns ;awn position to the east (x + 1)
LawnPos LawnPos::east() const {
    return LawnPos(x + 1, y);
}