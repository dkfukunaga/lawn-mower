
#include "tester.h"
#include "..\src\mower.h"

TEST_CASE("Test Mower contructor") {
    SUBCASE("Default constructor") {
        Mower mower;

        // make sure new lawn object created
        CHECK_FALSE(mower.getLawn() == nullptr);

        // make sure mower initialized to position (1,1)
        CHECK(mower.getPosition().x == Position(1,1).x);
        CHECK(mower.getPosition().y == Position(1,1).y);

        // make sure mower stats initialized to 0
        CHECK(mower.getPeeks() == 0);
        CHECK(mower.getSteps() == 0);
        CHECK(mower.getTurns() == 0);
    }
    SUBCASE("Full constructor") {
        Lawn *lawn = new Lawn();
        Mower mower(lawn);

        // make sure new lawn object created
        CHECK_FALSE(mower.getLawn() == nullptr);

        // make sure mower initialized to position (1,1)
        CHECK(mower.getPosition().x == Position(1,1).x);
        CHECK(mower.getPosition().y == Position(1,1).y);

        // make sure mower stats initialized to 0
        CHECK(mower.getPeeks() == 0);
        CHECK(mower.getSteps() == 0);
        CHECK(mower.getTurns() == 0);

        delete lawn;
    }
}

TEST_CASE("Test movement functionality and stats") {
    Lawn *lawn = new Lawn(10,12);
    Mower mower;

    // make sure mower in position (1,1)
    REQUIRE(mower.getPosition().x == 1);
    REQUIRE(mower.getPosition().y == 1);

    SUBCASE("Facing, Peek, Turn test") {
        // count for north, west, south, east
        int direction_count[4] = {0, 0, 0, 0};
        // count for error, wall, unmowed, mowed
        int square_count[4] = {0, 0, 0, 0};

        for (int i = 0; i < 4; ++i) {
            // get facing and increment direction_count
            Direction direction = mower.getFacing();
            direction_count[static_cast<int>(direction)]++;
            
            // get square and increment square_count
            // also increments peek count
            Square square = mower.peek();
            square_count[static_cast<int>(square)]++;

            // rotate counterclockwise
            mower.turnLeft();
        }

        // each direction should have been counted once
        CHECK(direction_count[0] == 1);
        CHECK(direction_count[1] == 1);
        CHECK(direction_count[2] == 1);
        CHECK(direction_count[3] == 1);

        // wall and unmowed should have been counted twice
        // no other squares should have been counted
        CHECK(square_count[static_cast<int>(Square::error)] == 0);
        CHECK(square_count[static_cast<int>(Square::wall)] == 2);
        CHECK(square_count[static_cast<int>(Square::unmowed)] == 2);
        CHECK(square_count[static_cast<int>(Square::mowed)] == 0);

        // there should be 4 peeks, 4 turns, 0 steps
        CHECK(mower.getPeeks() == 4);
        CHECK(mower.getTurns() == 4);
        CHECK(mower.getSteps() == 0);
    }

    delete lawn;
}