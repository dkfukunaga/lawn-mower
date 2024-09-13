

#ifndef LAWN_COMMON_H
#define LAWN_COMMON_H

// cardinal direction on lawn
enum class Direction {
    north,
    west,
    south,
    east
};

// square types on lawn
enum class SquareType {
    error,      // invalid square
    wall,       // red
    unmowed,    // green
    mowed       // green
};

// x y coordinates
struct Position {
    int     x;
    int     y;

    // construct new Position object
    Position(int new_x, int new_y):
        x(new_x),
        y(new_y) { };
    // construct new Position object at default (1,1)
    Position():
        x(1),
        y(1) { };

    // return Position to the north
    Position north() { return Position{x, y + 1}; }
    // return Position to the west
    Position west() { return Position{x - 1, y}; }
    // return Position to the south
    Position south() { return Position{x, y - 1}; }
    // return Position to the east
    Position east() { return Position{x + 1, y}; }

    // move to new Position by offset
    // returns new Position
    Position move(int x_offset, int y_offset) {
        x += x_offset;
        y += y_offset;
        return *this;
    }

    // set to new Position by coordinates
    // returns new Position
    Position set(int new_x, int new_y) {
        x = new_x;
        y = new_y;
        return *this;
    }

    bool operator==(Position *that) {
        return this->x == that->x && this->y == that->y;
    }

    bool operator!=(Position *that) {
        return !(this == that);
    }
};

typedef Position LawnPos;


#endif