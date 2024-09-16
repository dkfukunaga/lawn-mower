

#include "tester.h"
#include "..\src\direction.h"

TEST_CASE("Test directionString") {
    Direction north(Direction::north);
    Direction west(Direction::west);
    Direction south(Direction::south);
    Direction east(Direction::east);

    // check default case
    CHECK(getDirectionString(north) == "north");
    CHECK(getDirectionString(west) == "west");
    CHECK(getDirectionString(south) == "south");
    CHECK(getDirectionString(east) == "east");

    // check upper case
    CHECK(getDirectionString(north, LetterCase::upper) == "NORTH");
    CHECK(getDirectionString(west, LetterCase::upper) == "WEST");
    CHECK(getDirectionString(south, LetterCase::upper) == "SOUTH");
    CHECK(getDirectionString(east, LetterCase::upper) == "EAST");

    // check first upper
    CHECK(getDirectionString(north, LetterCase::firstUpper) == "North");
    CHECK(getDirectionString(west, LetterCase::firstUpper) == "West");
    CHECK(getDirectionString(south, LetterCase::firstUpper) == "South");
    CHECK(getDirectionString(east, LetterCase::firstUpper) == "East");
}

TEST_CASE("Test increment and decrement operators") {
    Direction dir1 = Direction::north;
    Direction dir2 = Direction::north;

    // test increment
    CHECK(dir1++ == Direction::north);
    CHECK(dir1 == Direction::west);
    CHECK(++dir1 == Direction::south);
    CHECK(dir1 == Direction::south);
    
    // test decrement
    CHECK(dir2-- == Direction::north);
    CHECK(dir2 == Direction::east);
    CHECK(--dir2 == Direction::south);
    CHECK(dir2 == Direction::south);
}