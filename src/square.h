
#ifndef SQUARE_H
#define SQUARE_H

#include "common.h"
#include <string>
#include <random>
#include <ctime>

class Square {
public:
    Square();
    Square(SquareType type);

    SquareType      getType();
    int             getVariant();
    std::string     getString();

    void            setType(SquareType type);
private:
    SquareType      _type;
    int             _variant;   // only used by unmowed squares

    static const std::string _error_string;
    static const std::string _wall_string;
    static const std::string _unmowed_string[2];  // can be randomized
    static const std::string _mowed_string;
};

#endif