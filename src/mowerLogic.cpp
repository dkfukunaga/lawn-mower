
#include "mowerLogic.h"






MowerLogic::MowerLogic() {

}

MowerLogic::MowerLogic(LawnDisplay *lawn_display, Algorithm algorithm = Algorithm::zigzag):
    _lawn_display(lawn_display),
    _algorithm(algorithm) { };


Algorithm MowerLogic::getAlgorithm() { return _algorithm; }

void MowerLogic::setAlogrithm(Algorithm algorithm) { _algorithm = algorithm; }

/***** BASIC MOWER ACTIONS *****/

// Instructs mower to peek the square in front of it.
//
// returns SquareType
SquareType MowerLogic::peek() {
    return _lawn_display->mowerPeek();
}

// Moves forward one step.
//
// returns true if successful,
// returns false if a wall collision occurs
bool MowerLogic::forward() {
    return _lawn_display->mowerForward();
}

// Turns mower right
void MowerLogic::turnRight() {
    _lawn_display->mowerTurnLeft();
}

// Turns mower left
void MowerLogic::turnLeft() {
    _lawn_display->mowerTurnRight();
}


/***** DERIVED MOWER ACTIONS *****/


// Moves forward n steps. If n is negative, moves until a wall collision.
// If a wall collision occurs, does not attempt more forward steps.
//
// returns number of actions taken.
int MowerLogic::forwardNSteps(int steps) {
    int counter = 0;
    bool has_moved = false;

    while ((steps < 0) || (counter < steps)) {
        has_moved = forward();
        counter++;
        if (!has_moved)
            break;
    }
    return counter;
}

// Uses peeks and turns to orient mower north from 1,1.
//
// returns number of actions taken.
int MowerLogic::orientNorthFromStart(Direction direction) {
    int counter = 0;
    SquareType next = peek();
    counter++;
    if (next == SquareType::wall){
        do {
            turnRight();
            next = peek();
            counter += 2;
        } while (next == SquareType::wall);
    } else {
        turnLeft();
        next == peek();
        counter += 2;
        if (next == SquareType::wall) {
            turnRight();
            counter++;
        }
    }
    return counter;
}




