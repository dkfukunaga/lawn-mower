

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

std::string getDirectionString(Direction direction, LetterCase letter_case = LetterCase::lower);

Direction& operator++(Direction &orig);
Direction& operator--(Direction &orig);
Direction operator++(Direction &orig, int);
Direction operator--(Direction &orig, int);


#endif