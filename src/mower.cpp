


#include "mower.h"

/***** CONSTRUCTORS *****/

// create a mower on the provided lawn
Mower::Mower(Lawn *lawn) {
    // set pointer to lawn
    _lawn = lawn;

    // set a random facing
    srand(time(NULL));
    _facing = static_cast<Direction>(rand() % 4);

    // set initial position lower left corner of grass
    _position = LawnPos(1, 1);

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
    _position = LawnPos(1, 1);

    // mow current position
    _lawn->mowSquare(_position);

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;
}

/***** GETTERS/ACCESSORS *****/

// returns direction the mower is facing
Direction Mower::getFacing() const { return _facing; }

// return coordinates of mower on lawn
LawnPos Mower::getPosition() const { return _position; }

// return current square
Square Mower::getSquare() const { return _lawn->getSquare(this->getPosition()); }

// returns pointer to the current lawn
Lawn* Mower::getLawn() const { return _lawn; }

// returns ascii character for mower depending on facing
char Mower::getMowerChar() const {
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
int Mower::getPeeks() const { return _peeks; }

// returns number of turns
int Mower::getTurns() const { return _turns; }

// returns number of steps
int Mower::getSteps() const { return _steps; }

// returns total actions taken
int Mower::getTotal() const { return _peeks + _turns + _steps; }

/***** SETTERS/MUTATORS *****/

// sets the mower's lawn to a new lawn and resets mower stats
void Mower::setLawn(Lawn *lawn) {
    // set lawn pointer to new lawn
    _lawn = lawn;

    // reset to lower left corner
    _position.set(1, 1);

    // set stats to 0
    _peeks = 0;
    _turns = 0;
    _steps = 0;
}

/***** PUBLIC MOWER ACTION FUNCTIONS *****/

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
        _position.move(Direction::north);
        break;
    case Direction::west:
        _position.move(Direction::west);
        break;
    case Direction::south:
        _position.move(Direction::south);
        break;
    case Direction::east:
        _position.move(Direction::east);
        break;
    }

    // mow new position
    _lawn->mowSquare(_position);
    
    return true;
}

/***** PRIVATE HELPER FUNCTIONS *****/

// return the square in front of the mower
SquareType Mower::checkNextSquare() {
    switch (_facing) {
    case Direction::north:
        return _lawn->getSquare(_position.north()).getType();
        break;
    case Direction::west:
        return _lawn->getSquare(_position.west()).getType();
        break;
    case Direction::south:
        return _lawn->getSquare(_position.south()).getType();
        break;
    case Direction::east:
        return _lawn->getSquare(_position.east()).getType();
        break;
    }
    return SquareType::error;
}

