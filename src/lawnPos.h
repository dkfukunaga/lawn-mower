

#ifndef LAWN_POSITION_H
#define LAWN_POSITOIN_H

#include "position.h"

struct LawnPos : Position {
    LawnPos();
    LawnPos(int new_x, int new_y);
    LawnPos(const LawnPos &other);

    LawnPos     north() const;
    LawnPos     west() const;
    LawnPos     south() const;
    LawnPos     east() const;
};



#endif