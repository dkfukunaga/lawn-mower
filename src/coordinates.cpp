

#include "coordinates.h"


bool            Coordinates::operator==(const Coordinates& other) const {
    return (this->x == other.x && this->y == other.y);
}

bool            Coordinates::operator!=(const Coordinates& other) const {
     return !(*this == other);
}

Coordinates&    Coordinates::operator=(const Coordinates& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}



