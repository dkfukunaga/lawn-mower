

#include "coordinates.h"


Coordinates     Coordinates::getNext(Direction direction) const {
    switch (direction) {
        case Direction::north:
            return Coordinates{x, y + 1};
            break;
        case Direction::east:
        return Coordinates{x + 1, y};
            break;
        case Direction::south:
        return Coordinates{x, y - 1};
            break;
        case Direction::west:
        return Coordinates{x - 1, y};
            break;
    }
}


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



