
#include "mowerLogic.h"





const Algorithm MowerLogic::_default_algorithm = Algorithm::zigzag;

MowerLogic::MowerLogic(LawnDisplay *lawn_display):
    _lawn_display(lawn_display),
    _algorithm(_default_algorithm) { };

MowerLogic::MowerLogic(LawnDisplay *lawn_display, Algorithm algorithm):
    _lawn_display(lawn_display),
    _algorithm(algorithm) { };


Algorithm MowerLogic::getAlgorithm() { return _algorithm; }

void MowerLogic::setAlogrithm(Algorithm algorithm) { _algorithm = algorithm; }

void MowerLogic::runAlgorithm(Algorithm algorithm = _default_algorithm) {
    switch (algorithm) {
        case Algorithm::manual:
            manualControl();
            break;
        case Algorithm::zigzag:
            zigzagAlgorithm();
            break;
        case Algorithm::spiral:
            spiralAlgorithm();
            break;
        default:
            return;
            break;
    }
}

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
int MowerLogic::orientNorthFromStart() {
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


CommandReturn MowerLogic::testAlgorithm(Command command, int arg = 0) {
    CommandReturn result;
    switch (command) {
        case Command::peek:
            result.type = peek();
            break;
        case Command::forward:
            result.success = forward();
            break;
        case Command::turnLeft:
            turnLeft();
            result.success = true;
            break;
        case Command::turnRight:
            turnRight();
            result.success = true;
            break;
        case Command::forwardNSteps:
            result.count = forwardNSteps(arg);
            break;
        case Command::orientNorthFromStart:
            result.count = orientNorthFromStart();
            break;
    }

    return result;
}


/***** MOWER ALGORITHMS *****/

void MowerLogic::zigzagAlgorithm() {

}

void MowerLogic::spiralAlgorithm() {

}

void MowerLogic::manualControl() {

}

