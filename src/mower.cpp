#include "mower.h"

// mower commands

SquareType          Mower::peek() {
    ++peeks_;
    return lawn_.getSquare(position_, facing_).getType();
}

bool                Mower::forward() {
    ++steps_;
    if (lawn_.getSquare(position_, facing_).getType() != SquareType::error &&
        lawn_.getSquare(position_, facing_).getType() != SquareType::wall) {
        position_ = position_.getNext(facing_);
        return true;
    }
    return false;
}

void                Mower::turnRight() {
    ++turns_;

    int temp = static_cast<int>(facing_);
    temp = (temp + 1) % 4;
    
    facing_ = static_cast<Direction>(temp);   
}

void                Mower::turnLeft() {
    ++turns_;

    /* 
     * Modulo* on a negative number gives a negative (e.g. (-1) % 4 = (-1)).
     * Therefore, instead of (temp - 1) to rotate ccw, I am using (temp + 3)
     * to avoid negative numbers by rotating (4 - 1) cw.
     * 
     * in C/C++, % is actually remainder, not modulo.
     */

    int temp = static_cast<int>(facing_);
    temp = (temp + 3) % 4;

    facing_ = static_cast<Direction>(temp); 
}

// setters

void                Mower::resetStats() {
    peeks_ = 0;
    steps_ = 0;
    turns_ = 0;
}

bool                Mower::setPosition(Coordinates position) {
    if (isValidPosition(position)) {
        position_ = position;
        return true;
    }
    return false;
}

void                Mower::setFacing(Direction facing) { facing_ = facing; }

// getters

Coordinates         Mower::getPosition() const { return position_; }

Direction           Mower::getFacing() const { return facing_; }

int                 Mower::getPeeks() const { return peeks_; }

int                 Mower::getSteps() const { return steps_; }

int                 Mower::getTurns() const { return turns_; }

std::string         Mower::getMowerString() const { return MOWER_STRINGS[static_cast<int>(facing_)]; }

std::string         Mower::getFacingnString() const { return FACING_STRINGS[static_cast<int>(facing_)]; }

// private helper functions

Direction           Mower::getRandomDirection() const { return static_cast<Direction>(rand() % 4); }

bool                Mower::isValidPosition(Coordinates position) const {
    return position.x >= 0 && position.x < lawn_.getWidth() &&
           position.y >= 0 && position.y < lawn_.getHeight();
}