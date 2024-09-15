
#ifndef MOWER_LOGIC_H
#define MOWER_LOGIC_H

#include "lawnDisplay.h"
#include <string>


enum class Algorithm {
    naive,
    blind,
    zigzag,
    spiral,
};

class MowerLogic {
public:
    MowerLogic();
    MowerLogic(LawnDisplay *lawn_display, Algorithm algorithm);

    Algorithm       getAlgorithm();
    void            setAlogrithm(Algorithm algorithm);
private:
    LawnDisplay     *_lawn_display;
    Algorithm       _algorithm;

    int             orient(Direction direction);
    SquareType      peek();
    int             forward(int steps);
    void            turnRight();
    void            turnLeft();
};


#endif