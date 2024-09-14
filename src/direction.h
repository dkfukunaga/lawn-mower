

#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

// cardinal direction on lawn
enum class Direction {
    north,
    west,
    south,
    east
};

static std::string getDirectionString(Direction direction) {
    std::string label;
    switch (direction) {
        case Direction::north:
            label = "north";
            break;
        case Direction::west:
            label = "west";
            break;
        case Direction::south:
            label = "south";
            break;
        case Direction::east:
            label = "east";
            break;
        default:
            label = "ERROR";
            break;
    }
    return label;
}

#endif