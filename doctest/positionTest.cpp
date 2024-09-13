
#include "tester.h"
#include "..\src\position.h"

TEST_CASE("Test constructors, set") {
    Position default_position;
    Position new_position(5, 7);
    Position copied_position(new_position);

    // check default position
    CHECK(default_position.getX() == 0);
    CHECK(default_position.getY() == 0);

    //check new position
    CHECK(new_position.getX() == 5);
    CHECK(new_position.getY() == 7);

    //check copied position
    CHECK(copied_position.getX() == 5);
    CHECK(copied_position.getY() == 7);

    // check deep copy
    copied_position.set(10, 13);
    CHECK_FALSE(new_position.getX() == 10);
    CHECK_FALSE(new_position.getY() == 13);
}

TEST_CASE("Test north(), west(), south(), east()") {
    // check that they return the correct position and don't move position
    Position position(5, 5);

    REQUIRE(position.getX() == 5);
    REQUIRE(position.getY() == 5);

    // test north()
    CHECK(position.north().getX() == 5);
    CHECK(position.north().getY() == 6);
    CHECK(position.getX() == 5);
    CHECK(position.getY() == 5);

    // test west()
    CHECK(position.west().getX() == 4);
    CHECK(position.west().getY() == 5);
    CHECK(position.getX() == 5);
    CHECK(position.getY() == 5);

    // test south()
    CHECK(position.south().getX() == 5);
    CHECK(position.south().getY() == 4);
    CHECK(position.getX() == 5);
    CHECK(position.getY() == 5);

    // test east()
    CHECK(position.east().getX() == 6);
    CHECK(position.east().getY() == 5);
    CHECK(position.getX() == 5);
    CHECK(position.getY() == 5);
}

TEST_CASE("Test move functoins") {

}

TEST_CASE("Test operator overloads") {

}