#include "mower.h"

const std::string Mower::MOWER_STRINGS[] = {"^", ">", "v", "<"};

// mower commands

SquareType          Mower::peek() {
    ++peeks_;
    return lawn_.getSquare(position_, facing_).getType();
}

bool                Mower::forward() {
    ++steps_;

    // Get the square in front of the mower at its current position
    SquareType nextSquareType = lawn_.getSquare(position_, facing_).getType();

    // Check if the square is valid and not a wall or error
    if (nextSquareType != SquareType::error && nextSquareType != SquareType::wall) {
        last_position_ = position_;
        position_ = position_.getNext(facing_);
        lawn_.mowSquare(position_);
        return true;
    }

    return false;
}

void                Mower::turnRight() {
    ++turns_;

    facing_ = static_cast<Facing::Direction>((facing_ + 1) % 4);
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

     facing_ = static_cast<Facing::Direction>((facing_ + 3) % 4);
}

// setters

void                Mower::resetStats() {
    peeks_ = 0;
    steps_ = 0;
    turns_ = 0;
}

bool                Mower::setPosition(Coordinates position) {
    if (lawn_.isValidPosition(position)) {
        position_ = position;
        last_position_ = Coordinates{-1, -1};
        return true;
    }
    return false;
}

void                Mower::setFacing(Facing::Direction facing) { facing_ = facing; }

// getters

Coordinates         Mower::getPosition() const { return position_; }

Coordinates         Mower::getLastPosition() const { return last_position_; }

Facing::Direction   Mower::getFacing() const { return facing_; }

int                 Mower::getPeeks() const { return peeks_; }

int                 Mower::getSteps() const { return steps_; }

int                 Mower::getTurns() const { return turns_; }

std::string         Mower::getMowerString() const { return MOWER_STRINGS[facing_]; }

std::string         Mower::getFacingString() const { return Facing::toString(facing_); }

// private helper functions

Facing::Direction   Mower::getRandomDirection() { return static_cast<Facing::Direction>(rand() % 4); }

