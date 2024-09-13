
#include "tester.h"
#include "..\src\mower.h"

TEST_CASE("Test Mower contructor") {
    SUBCASE("Default constructor") {
        Mower mower;

        // make sure new lawn object created
        CHECK_FALSE(mower.getLawn() == nullptr);

        // make sure mower initialized to position (1,1)
        CHECK(mower.getLawnPos().getX() == LawnPos(1,1).getX());
        CHECK(mower.getLawnPos().getY() == LawnPos(1,1).getY());

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
        CHECK(mower.getLawnPos().getX() == LawnPos(1,1).getX());
        CHECK(mower.getLawnPos().getY() == LawnPos(1,1).getY());

        // make sure mower stats initialized to 0
        CHECK(mower.getPeeks() == 0);
        CHECK(mower.getSteps() == 0);
        CHECK(mower.getTurns() == 0);

        delete lawn;
    }
}

TEST_CASE("Test movement functionality and stats") {
    Lawn *lawn = new Lawn(10,12);
    Mower mower(lawn);

    SUBCASE("getFacing(), peek(), turn() test") {
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
            SquareType square = mower.peek();
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
        CHECK(square_count[static_cast<int>(SquareType::error)] == 0);
        CHECK(square_count[static_cast<int>(SquareType::wall)] == 2);
        CHECK(square_count[static_cast<int>(SquareType::unmowed)] == 2);
        CHECK(square_count[static_cast<int>(SquareType::mowed)] == 0);

        // there should be 4 peeks, 4 turns, 0 steps
        CHECK(mower.getPeeks() == 4);
        CHECK(mower.getTurns() == 4);
        CHECK(mower.getSteps() == 0);
    }

    SUBCASE("getSquare(), forward(), turnLeft(), turnRight(), steps, lawnmowing test") {
        // make sure starting square is mowed
        REQUIRE(mower.getSquare().getType() == SquareType::mowed);

        // point mower north
        // and count turns
        int turns = 0;
        while (mower.getFacing() != Direction::north) {
            mower.turnLeft();
            turns++;
        }
        
        // make sure facing north
        REQUIRE(mower.getFacing() == Direction::north);
        // make sure position is (1,1)
        REQUIRE(mower.getLawnPos().getX() == 1);
        REQUIRE(mower.getLawnPos().getY() == 1);

        // conduct series of moves
        mower.forward();        // y++ (1, 2)   steps = 1
        mower.forward();        // y++ (1, 3)   steps = 2
        mower.turnRight();      // facing east  turns = 1
        mower.forward();        // x++ (2, 3)   steps = 3
        mower.turnLeft();       // facing north turns = 2
        mower.forward();        // y++ (2, 4)   steps = 4

        // check current position
        REQUIRE(mower.getLawnPos().getX() == 2);
        REQUIRE(mower.getLawnPos().getY() == 4);

        // check squares that were mowed
        CHECK(mower.getLawn()->getSquare(LawnPos(2, 4)).getType() == SquareType::mowed);
        CHECK(mower.getLawn()->getSquare(LawnPos(2, 3)).getType() == SquareType::mowed);
        CHECK(mower.getLawn()->getSquare(LawnPos(1, 3)).getType() == SquareType::mowed);
        CHECK(mower.getLawn()->getSquare(LawnPos(1, 2)).getType() == SquareType::mowed);
        CHECK(mower.getLawn()->getSquare(LawnPos(1, 1)).getType() == SquareType::mowed);

        // check next square is unmowed
        CHECK(mower.peek() == SquareType::unmowed); // peeks = 1

        // check stats
        CHECK(mower.getSteps() == 4);
        CHECK(mower.getTurns() == 2  + turns);  // include turns from reorientation north
        CHECK(mower.getPeeks() == 1);
        CHECK(mower.getTotal() == 7 + turns);
    }

    SUBCASE("check if forward() runs into wall") {
        // point mower south
        while (mower.getFacing() != Direction::south) {
            mower.turnLeft();
        }
        // check for wall
        REQUIRE(mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(mower.forward());
        CHECK_FALSE(mower.forward());

        // point mower west
        mower.turnRight();
        // check for wall
        REQUIRE(mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(mower.forward());
        CHECK_FALSE(mower.forward());

        // point mower north
        mower.turnRight();

        // move north until hit wall
        while (true) {
            if (!mower.forward())
                break;
        }
        // check for wall
        REQUIRE(mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(mower.forward());
        CHECK_FALSE(mower.forward());
        // check mower position
        CHECK(mower.getLawnPos().getY() == 10);

        // point mower east
        mower.turnRight();

        // move east until hit wall
        while (true) {
            if (!mower.forward())
                break;
        }
        // check for wall
        REQUIRE(mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(mower.forward());
        CHECK_FALSE(mower.forward());
        // check mower position
        CHECK(mower.getLawnPos().getX() == 8);
    }

    delete lawn;
}

TEST_CASE("Test getMowerChar()") {
    Mower mower;

    // point mower north
    while (mower.getFacing() != Direction::north) {
        mower.turnLeft();
    }

    // double check facing
    REQUIRE(mower.getFacing() == Direction::north);

    // check all four directions
    CHECK(mower.getMowerChar() == '^');
    mower.turnLeft();
    CHECK(mower.getMowerChar() == '<');
    mower.turnLeft();
    CHECK(mower.getMowerChar() == 'v');
    mower.turnLeft();
    CHECK(mower.getMowerChar() == '>');
}