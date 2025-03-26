#include "mower.h"

SquareType          Mower::peek() {
    switch (facing_) {
        case Direction::north:
            Coordinates pos = getPosition().north();
            if (isValidPosition(pos)) {
                return lawn_.getSquare(pos).getType();
            }
            return SquareType::error;
            break;
        case Direction::east:
        Coordinates pos = getPosition().east();
        if (isValidPosition(pos)) {
            return lawn_.getSquare(pos).getType();
        }
        return SquareType::error;
            break;
        case Direction::south:
        Coordinates pos = getPosition().south();
        if (isValidPosition(pos)) {
            return lawn_.getSquare(pos).getType();
        }
        return SquareType::error;
            break;
        case Direction::west:
        Coordinates pos = getPosition().west();
        if (isValidPosition(pos)) {
            return lawn_.getSquare(pos).getType();
        }
        return SquareType::error;
            break;
        default:
            return SquareType::error;
            break;
    }
}
bool                Mower::forward() {
    
}
void                Mower::turnRight() {
    
}
void                Mower::turnLeft() {
    
}

bool                Mower::setPosition(Coordinates position) {
    if (isValidPosition(position)) {
        position_ = position;
        return true;
    }
    return false;
}

void                Mower::setFacing(Direction facing) { facing_ = facing; }

Coordinates         Mower::getPosition() const { return position_; }
Direction           Mower::getFacing() const { return facing_; }
int                 Mower::getPeeks() const { return peeks_; }
int                 Mower::getSteps() const { return steps_; }
int                 Mower::getTurns() const { return turns_; }
std::string         Mower::getString() const { return MOWER_STRING; }

Direction           Mower::getRandomDirection() const { return static_cast<Direction>(rand() % 4); }

void                Mower::resetStats() {
    peeks_ = 0;
    steps_ = 0;
    turns_ = 0;
}

bool                Mower::isValidPosition(Coordinates position) const {
    return position.x >= 0 && position.x < lawn_.getWidth() &&
           position.y >= 0 && position.y < lawn_.getHeight();
}