

#ifndef LAWN_COMMON_H
#define LAWN_COMMON_H


enum class Direction {
    north,
    west,
    south,
    east
};


enum class Square {
    wall,       // red
    unmowed,    // green
    mowed       // green
};


struct Position {
    int     x;
    int     y;
};


#endif