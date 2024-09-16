

#include "lawnPos.h"


LawnPos::LawnPos(): Position(0,0) { }

LawnPos::LawnPos(int new_x, int new_y): Position(new_x, new_y) { }

LawnPos::LawnPos(const LawnPos &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
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