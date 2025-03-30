#pragma once
#ifndef FACING_H
#define FACING_H

#include <string>

namespace Facing {
    enum Direction {
        north = 0,
        east,
        south,
        west
    };

    static std::string toString(Direction dir) {
        switch (dir) {
            case north:
                return "north";
            case east:
                return "east";
            case south:
                return "south";
            case west:
                return "west";
            default:
                return "error";
        }
    }
}



#endif