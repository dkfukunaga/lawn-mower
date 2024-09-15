
#ifndef MOWER_LOGIC_H
#define MOWER_LOGIC_H

#include "lawnDisplay.h"
#include <string>


enum class Algorithm {
    manual,
    zigzag,
    spiral,
    test,
};

enum class Command {
    peek,
    forward,
    turnRight,
    turnLeft,
    forwardNSteps,
    orientNorthFromStart,
};

union CommandReturn {
    SquareType      type;
    int             count;
    bool            success;
};

class MowerLogic {
public:
    MowerLogic() = delete;
    MowerLogic(LawnDisplay *lawn_display);
    MowerLogic(LawnDisplay *lawn_display, Algorithm algorithm);

    Algorithm       getAlgorithm();
    void            setAlogrithm(Algorithm algorithm);

    void            runAlgorithm(Algorithm algorithm);
    CommandReturn   testAlgorithm(Command command, int arg);
private:
    static const Algorithm _default_algorithm;
    LawnDisplay     *_lawn_display;
    Algorithm       _algorithm;

    SquareType      peek();
    bool            forward();
    void            turnRight();
    void            turnLeft();

    int             forwardNSteps(int steps);
    int             orientNorthFromStart();

    void            zigzagAlgorithm();
    void            spiralAlgorithm();
    void            manualControl();
};


#endif