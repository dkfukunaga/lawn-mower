

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

// enum for letter case
enum class LetterCase {
    lower,
    upper,
    firstUpper
};

// returns string of cardinal direction with option for letter case
//
// LetterCase::lower - all lower case
// LetterCase::upper - all upper case
// LetterCase::firstUpper - first upper case rest lower case
//
// defaults to LetterCase::lower
static std::string getDirectionString(Direction direction, LetterCase letter_case = LetterCase::lower) {
    std::string label;
    switch (direction) {
        case Direction::north:
            label = (letter_case == LetterCase::lower ? "north" :
                    (letter_case == LetterCase::upper ? "NORTH" : "North"));
            break;
        case Direction::west:
            label = (letter_case == LetterCase::lower ? "west" :
                    (letter_case == LetterCase::upper ? "WEST" : "West"));
            break;
        case Direction::south:
            label = (letter_case == LetterCase::lower ? "south" :
                    (letter_case == LetterCase::upper ? "SOUTH" : "South"));
            break;
        case Direction::east:
            label = (letter_case == LetterCase::lower ? "east" :
                    (letter_case == LetterCase::upper ? "EAST" : "East"));
            break;
        default:
            label = "ERROR";
            break;
    }
    return label;
}

#endif