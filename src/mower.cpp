


#include "mower.h"

// create a mower on the provided lawn
Mower::Mower(Lawn *lawn) {
    // set pointer to lawn
    _lawn = lawn;

    // set a random facing
    srand(time(NULL));
    _facing = static_cast<Direction>(rand() % 4);

    // set initial position lower left corner of grass
    _position = Position(1, 1);

    // mow current position
    _lawn->mowSquare(_position);

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;
}

// create a mower on a new randomly sized lawn
Mower::Mower() {
    // set pointer to new random lawn
    _lawn = new Lawn();

    // set a random facing
    srand(time(NULL));
    _facing = static_cast<Direction>(rand() % 4);

    // set initial position lower left corner of grass
    _position = Position(1, 1);

    // mow current position
    _lawn->mowSquare(_position);

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;
}

// returns direction the mower is facing
Direction Mower::getFacing() { return _facing; }

// return coordinates of mower on lawn
Position Mower::getPosition() { return _position; }

// return current square
SquareType Mower::getSquare() { return _lawn->getSquare(this->getPosition()); }

// returns pointer to the current lawn
Lawn* Mower::getLawn() { return _lawn; }

// returns ascii character for mower depending on facing
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

// returns number of peeks
int Mower::getPeeks() { return _peeks; }

// returns number of turns
int Mower::getTurns() { return _turns; }

// returns number of steps
int Mower::getSteps() { return _steps; }

// sets the mower's lawn to a new lawn and resets mower stats
void Mower::setLawn(Lawn *lawn) {
    // set lawn pointer to new lawn
    _lawn = lawn;

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;
}

// mower turns to the left and increments turn counter
void Mower::turnLeft() {
    int temp = static_cast<int>(_facing);
    temp = (temp + 1) % 4;

    _facing = static_cast<Direction>(temp);

    _turns++;
}

// mower turns right and increments turn counter
void Mower::turnRight() {
    int temp = static_cast<int>(_facing);
    temp = (temp + 3) % 4;

    _facing = static_cast<Direction>(temp);

    _turns++;
}

// returns the square in front of the mower and increments peeks
SquareType Mower::peek() {
    _peeks++;
    return checkNextSquare();
}

// moves the mower forward if it is able to move and returns true.
// if there is a wall in front of the mower, it does not move and returns false.
// in either case, increments steps
bool Mower::forward() {

    _steps++;

    // check for wall
    if (checkNextSquare() == SquareType::wall)
        return false;
    
    // change position
    switch (_facing) {
    case Direction::north:
        _position = _position.north();
        break;
    case Direction::west:
        _position = _position.west();
        break;
    case Direction::south:
        _position = _position.south();
        break;
    case Direction::east:
        _position = _position.east();
        break;
    }

    // mow new position
    _lawn->mowSquare(_position);
    
    return true;
}

// return the square in front of the mower
SquareType Mower::checkNextSquare() {
    switch (_facing) {
    case Direction::north:
        return _lawn->getSquare(_position.north());
        break;
    case Direction::west:
        return _lawn->getSquare(_position.west());
        break;
    case Direction::south:
        return _lawn->getSquare(_position.south());
        break;
    case Direction::east:
        return _lawn->getSquare(_position.east());
        break;
    }
    return SquareType::error;
}

