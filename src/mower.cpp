


#include "mower.h"


Mower::Mower(Lawn *lawn) {
    // set pointer to lawn
    _lawn = lawn;

    // set a random facing
    srand(time(NULL));
    _facing = static_cast<Direction>(rand() % 4);

    // set initial position lower left corner of grass
    _position = {1,1};

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;
}

Direction Mower::getFacing() { return _facing; }

Position Mower::getPosition() { return _position; }

int Mower::getPeeks() { return _peeks; }

int Mower::getTurns() { return _turns; }

int Mower::getSteps() { return _steps; }

Lawn* Mower::getLawn() { return _lawn; }

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

void Mower::setLawn(Lawn *lawn) { _lawn = lawn; }

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
    _peeks++;
    return checkSquare();
}

bool Mower::forward() {

    _steps++;

    if (checkSquare() == Square::wall)
        return false;
    
    switch (_facing) {
    case Direction::north:
        _position = {_position.x, _position.y + 1};
        break;
    case Direction::west:
        _position = {_position.x - 1, _position.y};
        break;
    case Direction::south:
        _position = {_position.x, _position.y - 1};
        break;
    case Direction::east:
        _position = {_position.x + 1, _position.y};
        break;
    }
    return true;
}

// return the square in front of the mower
Square Mower::checkSquare() {
    switch (_facing) {
    case Direction::north:
        return _lawn->getSquare(_position.x, _position.y + 1);
        break;
    case Direction::west:
        return _lawn->getSquare(_position.x - 1, _position.y);
        break;
    case Direction::south:
        return _lawn->getSquare(_position.x, _position.y - 1);
        break;
    case Direction::east:
        return _lawn->getSquare(_position.x + 1, _position.y);
        break;
    }
}

