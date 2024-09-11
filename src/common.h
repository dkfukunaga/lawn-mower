

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

    Position north() { return Position{x, y + 1}; }
    Position west() { return Position{x - 1, y}; }
    Position south() { return Position{x, y + 1}; }
    Position east() { return Position{x + 1, y}; }
};


#endif