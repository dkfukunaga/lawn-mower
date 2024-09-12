
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
    std::string     getString();
    void            setType(SquareType type);
private:
    SquareType      _type;

    static const std::string _error_string;
    static const std::string _wall_string;
    static const std::string _unmowed_string[2];  // can be randomized
    static const std::string _mowed_string;
};

#endif