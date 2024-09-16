
#include "tester.h"
#include "..\src\position.h"

TEST_CASE("Test constructors, set") {
    Position default_position;
    Position new_position(5, 7);
    Position copied_position(new_position);

    // check default position
    CHECK(default_position.x == 0);
    CHECK(default_position.y == 0);

    //check new position
    CHECK(new_position.x == 5);
    CHECK(new_position.y == 7);

    //check copied position
    CHECK(copied_position.x == 5);
    CHECK(copied_position.y == 7);
}

TEST_CASE("Test operator overloads") {
    Position pos1(4, 7);
    Position pos2(4, 7);
    Position pos3(7, 4);

    // verify starting positions
    REQUIRE(pos1.x == 4);
    REQUIRE(pos1.y == 7);
    REQUIRE(pos2.x == 4);
    REQUIRE(pos2.y == 7);
    REQUIRE(pos3.x == 7);
    REQUIRE(pos3.y == 4);

    // test comparison operators
    // test comparison operators
    bool pos1_pos2 = pos1 == pos2;  // true
    bool pos1_pos3 = pos1 == pos3;  // false
    bool pos2_pos3 = pos2 != pos3;  // true

    CHECK(pos1_pos2);
    CHECK_FALSE(pos1_pos3);
    CHECK(pos2_pos3);

    pos1 = pos3;

    // test assignment operator
    CHECK(pos1.x == pos3.x);
    CHECK(pos1.y == pos3.y);
}

TEST_CASE("Test good()") {
    Position good_position;
    Position bad_position1(-1, 0);
    Position bad_position2(0, -1);
    Position bad_position3(-1, -1);

    CHECK(good_position.good());
    CHECK_FALSE(bad_position1.good());
    CHECK_FALSE(bad_position2.good());
    CHECK_FALSE(bad_position3.good());
}