
#ifndef MOWER_LOGIC_H
#define MOWER_LOGIC_H

#include "lawnDisplay.h"
#include <string>


enum class Algorithm {
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

    SquareType      peek();
    bool            forward();
    void            turnRight();
    void            turnLeft();

    int             forwardNSteps(int steps);
    int             orientNorthFromStart(Direction direction);
};


#endif