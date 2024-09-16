


#include "mower.h"

/***** CONSTRUCTORS/DESTRUCTORS *****/

// create a mower on a new randomly sized lawn
Mower::Mower() {
    lawn = nullptr;
    reset();
}

Mower::Mower(Lawn *newlawn) {
    lawn = newlawn;
    reset();
}

// returns the square in front of the mower and increments peeks
SquareType Mower::peek() {
    peeks++;
    
    switch (facing) {
    case Direction::north:
        return lawn->getSquare(lawn_pos.north()).getType();
        break;
    case Direction::west:
        return lawn->getSquare(lawn_pos.west()).getType();
        break;
    case Direction::south:
        return lawn->getSquare(lawn_pos.south()).getType();
        break;
    case Direction::east:
        return lawn->getSquare(lawn_pos.east()).getType();
        break;
    }
    return SquareType::error;
}

// moves the mower forward if it is able to move and returns true.
// if there is a wall in front of the mower, it does not move and returns false.
// in either case, increments steps
bool Mower::forward() {

    steps++;

    SquareType next = peek();
    peeks--;    // this peek doesn't count towards the count

    // verify next square is a lawn square
    if (next != SquareType::unmowed || next != SquareType::mowed)
        return false;
    
    // change position
    switch (facing) {
    case Direction::north:
        lawn_pos.move(Direction::north);
        break;
    case Direction::west:
        lawn_pos.move(Direction::west);
        break;
    case Direction::south:
        lawn_pos.move(Direction::south);
        break;
    case Direction::east:
        lawn_pos.move(Direction::east);
        break;
    }

    // mow new position
    lawn->mowSquare(lawn_pos);
    
    return true;
}

// mower turns to the left and increments turn counter
void Mower::turnLeft() {
    int temp = static_cast<int>(facing);
    temp = (temp + 1) % 4;

    facing = static_cast<Direction>(temp);

    turns++;
}

// mower turns right and increments turn counter
void Mower::turnRight() {
    int temp = static_cast<int>(facing);
    temp = (temp + 3) % 4;

    facing = static_cast<Direction>(temp);

    turns++;
}

// returns total actions taken
int Mower::getTotal() const { return peeks + turns + steps; }

// reset stats and LawnPos, roll random facing
void Mower::reset() {
    // set a random facing
    srand(time(NULL));
    facing = static_cast<Direction>(rand() % 4);

    // set initial position lower left corner of grass
    lawn_pos = LawnPos(1, 1);

    // set stats to 0
    peeks = 0;
    turns = 0;
    steps = 0;
}