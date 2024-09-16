

#ifndef LAWN_POSITION_H
#define LAWN_POSITION_H

#include "position.h"

struct LawnPos : Position {
    LawnPos();
    LawnPos(int new_x, int new_y);
    LawnPos(const LawnPos &other);

    LawnPos     set(int new_x, int new_y);
    LawnPos     set(LawnPos lawn_pos);

    LawnPos     move(Direction direction);
    LawnPos     north() const;
    LawnPos     west() const;
    LawnPos     south() const;
    LawnPos     east() const;
};



#endif