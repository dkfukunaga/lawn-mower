

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
};


#endif