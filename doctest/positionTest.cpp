
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

TEST_CASE("Test move functions") {
    Position position(5, 5);

    // verify correct starting position
    REQUIRE(position.getX() == 5);
    REQUIRE(position.getY() == 5);

    // test move(x, y)
    position.move(-1, 2);
    CHECK(position.getX() == 4);
    CHECK(position.getY() == 7);

    position.move(3, -4);
    CHECK(position.getX() == 7);
    CHECK(position.getY() == 3);

    // test move(north)
    CHECK(position.move(Direction::north).getY() == 4);
    CHECK(position.getY() == 4);
    CHECK(position.getX() == 7);

    // test move(west)
    CHECK(position.move(Direction::west).getX() == 6);
    CHECK(position.getY() == 4);
    CHECK(position.getX() == 6);
}

TEST_CASE("Test operator overloads") {
    Position pos1(4, 7);
    Position pos2(4, 7);
    Position pos3(7, 4);

    // verify starting positions
    REQUIRE(pos1.getX() == 4);
    REQUIRE(pos1.getY() == 7);
    REQUIRE(pos2.getX() == 4);
    REQUIRE(pos2.getY() == 7);
    REQUIRE(pos3.getX() == 7);
    REQUIRE(pos3.getY() == 4);

    bool pos1_pos2 = pos1 == pos2;  // true
    bool pos1_pos3 = pos1 == pos3;  // false
    bool pos2_pos3 = pos2 != pos3;  // true

    CHECK(pos1_pos2);
    CHECK_FALSE(pos1_pos3);
    CHECK(pos2_pos3);
}