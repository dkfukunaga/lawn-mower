
#ifndef COORDINATES_H
#define COORDINATES_H

#include "facing.h"


struct Coordinates {
    int             x;
    int             y;

    Coordinates     getNext(Facing::Direction direction) const;

    bool            operator==(const Coordinates& other) const;
    bool            operator!=(const Coordinates& other) const;
    Coordinates&    operator=(const Coordinates& other);
};




#endif