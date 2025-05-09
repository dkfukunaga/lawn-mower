#pragma once
#ifndef COORDINATES_H
#define COORDINATES_H

#include "facing.h"


struct Coordinates {
    int             x;
    int             y;

    Coordinates     getNext(Facing::Direction direction);
    Coordinates     delta(int x_delta, int y_delta);

    bool            operator==(const Coordinates& other) const;
    bool            operator!=(const Coordinates& other) const;
    Coordinates&    operator=(const Coordinates& other);
};




#endif