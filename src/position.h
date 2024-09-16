

#ifndef POSITION_H
#define POSITION_H

#include "direction.h"


struct Position {
    int         x;
    int         y;

    Position();
    Position(int new_x, int new_y);
    Position(const Position &other);

    bool        good();

    Position&   operator=(const Position &rhs);
    bool        operator==(const Position &rhs);
    bool        operator!=(const Position &rhs);
};


// typedef Position LawnPos;

#endif