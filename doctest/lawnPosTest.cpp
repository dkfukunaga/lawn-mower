
#include "tester.h"
#include "..\src\lawnPos.h"



TEST_CASE("Test constructors, set") {
    LawnPos def_lawn_pos;
    LawnPos new_lawn_pos(5, 7);
    LawnPos copied_lawn_pos(new_lawn_pos);

    // check default position
    CHECK(def_lawn_pos.x == 0);
    CHECK(def_lawn_pos.y == 0);

    //check new position
    CHECK(new_lawn_pos.x == 5);
    CHECK(new_lawn_pos.y == 7);

    //check copied position
    CHECK(copied_lawn_pos.x == 5);
    CHECK(copied_lawn_pos.y == 7);
}

TEST_CASE("Test set") {
    LawnPos lawn_pos1(3,3);
    LawnPos lawn_pos2(2,5);
    LawnPos lawn_pos3(8,1);

    // verify starting position
    REQUIRE(lawn_pos1.x == 3);
    REQUIRE(lawn_pos1.y == 3);

    lawn_pos1.set(11,17);

    CHECK(lawn_pos1.x == 11);
    CHECK(lawn_pos1.y == 17);

    // verify starting position
    REQUIRE(lawn_pos2.x == 2);
    REQUIRE(lawn_pos2.y == 5);
    REQUIRE(lawn_pos3.x == 8);
    REQUIRE(lawn_pos3.y == 1);

    lawn_pos2.set(lawn_pos3);

    CHECK(lawn_pos2.x == lawn_pos3.x);
    CHECK(lawn_pos2.y == lawn_pos3.y);

    lawn_pos3.x = 12;
    lawn_pos3.y = 20;

    CHECK_FALSE(lawn_pos2.x == 12);
    CHECK_FALSE(lawn_pos2.y == 20);

}


TEST_CASE("Test north(), west(), south(), east()") {
    int x = 3;
    int y = 12;
    // check that they return the correct position and don't move position
    LawnPos lawn_pos(x, y);

    REQUIRE(lawn_pos.x == x);
    REQUIRE(lawn_pos.y == y);

    SUBCASE("test north()") {
        CHECK(lawn_pos.north().x == x);
        CHECK(lawn_pos.north().y == y + 1);
        CHECK(lawn_pos.x == x);
        CHECK(lawn_pos.y == y);
    }

    SUBCASE("test west()") {
        CHECK(lawn_pos.west().x == x - 1);
        CHECK(lawn_pos.west().y == y);
        CHECK(lawn_pos.x == x);
        CHECK(lawn_pos.y == y);
    }

    SUBCASE("test south()") {
        CHECK(lawn_pos.south().x == x);
        CHECK(lawn_pos.south().y == y - 1);
        CHECK(lawn_pos.x == x);
        CHECK(lawn_pos.y == y);
    }

    SUBCASE("test east()") {
        CHECK(lawn_pos.east().x == x + 1);
        CHECK(lawn_pos.east().y == y);
        CHECK(lawn_pos.x == x);
        CHECK(lawn_pos.y == y);
    }
}

TEST_CASE("Test move function") {
    int x = 5;
    int y = 8;

    LawnPos pos(x,y);

    REQUIRE(pos.x == x);
    REQUIRE(pos.y == y);

    SUBCASE("move(Direction::north)") {
        pos.move(Direction::north);

        CHECK(pos.x == x);
        CHECK(pos.y == ++y);
    }

    SUBCASE("move(Direction::west)") {
        pos.move(Direction::west);

        CHECK(pos.x == --x);
        CHECK(pos.y == y);
    }

    SUBCASE("move(Direction::south)") {
        pos.move(Direction::south);

        CHECK(pos.x == x);
        CHECK(pos.y == --y);
    }

    SUBCASE("move(Direction::east)") {
        pos.move(Direction::east);

        CHECK(pos.x == ++x);
        CHECK(pos.y == y);
    }
}