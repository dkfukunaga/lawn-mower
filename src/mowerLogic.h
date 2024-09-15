
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
    MowerLogic(Algorithm algorithm);

    Algorithm       getAlgorithm();
    bool            setAlogrithm(Algorithm algorithm);
private:
    Algorithm       _current_algorithm;

    int             orient(Direction direction);
    SquareType      peek();
    bool            forward();
    int             forward(int steps);
    int             forwardToWall();
    void            turnRight();
    void            turnLeft();
};


#endif