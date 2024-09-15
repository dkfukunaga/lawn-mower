
#include "mowerLogic.h"






MowerLogic::MowerLogic() {

}

MowerLogic::MowerLogic(LawnDisplay *lawn_display, Algorithm algorithm = Algorithm::naive):
    _lawn_display(lawn_display),
    _algorithm(algorithm) { };


// return number of actions taken
int MowerLogic::orient(Direction direction) {

}

// return SquareType in front of mower
SquareType MowerLogic::peek() {

}

Algorithm MowerLogic::getAlgorithm() { return _algorithm; }

void MowerLogic::setAlogrithm(Algorithm algorithm) { _algorithm = algorithm; }


// moves forward n steps.
// if a wall collision occurs, does not attempt more forward steps.
//
// negative value will step forward until a wall collision.
// defaults to 1 step.
//
// return 0 for successful completion,
// return negative int for difference between steps taken and steps attempted
int MowerLogic::forward(int steps = 1) {

}

// turns mower right
void MowerLogic::turnRight() {

}

// turns mower left
void MowerLogic::turnLeft() {

}

