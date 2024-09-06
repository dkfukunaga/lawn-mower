


#include "mower.h"


Mower::Mower() {
    // create a new lawn
    _lawn = new Lawn();

    // set a random facing
    srand(time(NULL));
    _facing = static_cast<Direction>(rand() % 4);

    // set initial position lower left corner of grass
    _position = {1,1};

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;}


Direction Mower::getFacing() { return _facing; }

Position Mower::getPosition() { return _position; }

int Mower::getPeeks() { return _peeks; }

int Mower::getTurns() { return _turns; }

int Mower::getSteps() { return _steps; }

char Mower::getMowerChar() {
    switch (_facing) {
    case Direction::north:
        return '^';
        break;
    case Direction::west:
        return '<';
        break;
    case Direction::south:
        return 'v';
        break;
    case Direction::east:
        return '>';
        break;
    
    default:
        return '?';
        break;
    }
}

void Mower::turnLeft() {
    int temp = static_cast<int>(_facing);
    temp = (temp + 3) % 4;

    _facing = static_cast<Direction>(temp);

    _turns++;
}

void Mower::turnRight() {
    int temp = static_cast<int>(_facing);
    temp = (temp + 1) % 4;

    _facing = static_cast<Direction>(temp);

    _turns++;
}

Square Mower::peek() {

}

bool Mower::forward() {

}


bool Mower::canMove() {
    switch (_facing) {
    case Direction::north:
        if (_lawn->getSquare(_position.x, _position.y + 1) == Square::wall)
            return false;
        return true;
        break;
    case Direction::west:
        if (_lawn->getSquare(_position.x - 1, _position.y) == Square::wall)
            return false;
        return true;
        break;
    case Direction::south:
        if (_lawn->getSquare(_position.x, _position.y - 1) == Square::wall)
            return false;
        return true;
        break;
    case Direction::east:
        if (_lawn->getSquare(_position.x + 1, _position.y) == Square::wall)
            return false;
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

