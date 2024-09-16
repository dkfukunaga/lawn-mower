
#include "direction.h"

// returns string of cardinal direction with option for letter case
//
// LetterCase::lower - all lower case
// LetterCase::upper - all upper case
// LetterCase::firstUpper - first upper case rest lower case
//
// defaults to LetterCase::lower
std::string getDirectionString(Direction direction, LetterCase letter_case) {
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

Direction& operator++(Direction &orig) {
    int temp = static_cast<int>(orig);
    temp = (temp + 1) % 4;
    orig =  static_cast<Direction>(temp);
    return orig;
}

Direction& operator--(Direction &orig) {
    int temp = static_cast<int>(orig);
    temp = (temp == 0 ? 3 : temp - 1);
    orig =  static_cast<Direction>(temp);
    return orig;
}

Direction operator++(Direction &orig, int) {
    Direction old = orig;
    ++orig;
    return old;
}

Direction operator--(Direction &orig, int) {
    Direction old = orig;
    --orig;
    return old;
}