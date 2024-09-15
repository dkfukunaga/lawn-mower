
#ifndef MOWER_LOGIC_H
#define MOWER_LOGIC_H

#include "lawnDisplay.h"
#include <string>


enum class Algorithm {
    manual,
    zigzag,
    spiral,
};

class MowerLogic {
public:
    MowerLogic() = delete;
    MowerLogic(LawnDisplay *lawn_display);
    MowerLogic(LawnDisplay *lawn_display, Algorithm algorithm);

    Algorithm       getAlgorithm();
    void            setAlogrithm(Algorithm algorithm);

    void            runAlgorithm(Algorithm algorithm);
private:
    static const Algorithm _default_algorithm;
    LawnDisplay     *_lawn_display;
    Algorithm       _algorithm;

    SquareType      peek();
    bool            forward();
    void            turnRight();
    void            turnLeft();

    int             forwardNSteps(int steps);
    int             orientNorthFromStart(Direction direction);

    void            zigzagAlgorithm();
    void            spiralAlgorithm();
    void            manualControl();
};


#endif