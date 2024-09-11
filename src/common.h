

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
enum class Square {
    error,      // invalid square
    wall,       // red
    unmowed,    // green
    mowed       // green
};

// x y coordinates
struct Position {
    int     x;
    int     y;

    // return Square to the north
    Position north() { return Position{x, y + 1}; }
    // return Square to the west
    Position west() { return Position{x - 1, y}; }
    // return Square to the south
    Position south() { return Position{x, y + 1}; }
    // return Square to the east
    Position east() { return Position{x + 1, y}; }
};


#endif