#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "..\src\square.h"
#include "..\src\coordinates.h"
#include "..\src\facing.h"
#include "..\src\lawn.h"
#include "..\src\mower.h"
#include "..\src\lawnDisplay.h"
#include <string>
#include <random>
#include <time.h>


TEST_CASE("Square Test") {
    Coordinates testCoordinates{1,4};

    Square *defaultSquare = new Square();
    Square *mowedSquare = new Square(SquareType::mowed);
    Square *unmowedSquare = new Square(SquareType::unmowed, testCoordinates);
    Square *wallSquare = new Square(SquareType::wall, 0, 0);

    SUBCASE("Square constructor tests") {
        // default constructor
        CHECK(defaultSquare->getType() == SquareType::unmowed);
        CHECK(defaultSquare->getCoordinates() == Coordinates{-1, -1});

        // SquareType constructor
        CHECK(mowedSquare->getType() == SquareType::mowed);
        CHECK(mowedSquare->getCoordinates() == Coordinates{-1, -1});

        // Coordinates constructor
        CHECK(unmowedSquare->getType() == SquareType::unmowed);
        CHECK(unmowedSquare->getCoordinates() == testCoordinates);

        // X, Y constructor
        CHECK(wallSquare->getType() == SquareType::wall);
        CHECK(wallSquare->getCoordinates() == Coordinates{0, 0});
    }

    SUBCASE("Square getString tests") {

        std::string mowedString = " .";
        std::string unmowedString1 = "\",";
        std::string unmowedString2 = ",\"";
        std::string wallString = "  ";

        CHECK(mowedSquare->getString().compare(mowedString) == 0);
        // CHECK(unmowedSquare->getString().find('\"') != std::string::npos);
        // CHECK(unmowedSquare->getString().find(',') != std::string::npos);
        CHECK(wallSquare->getString().compare(wallString) == 0);
    }

    SUBCASE("Square setter tests") {
        defaultSquare->setType(SquareType::mowed);
        CHECK(defaultSquare->getType() == SquareType::mowed);
        defaultSquare->setType(SquareType::wall);
        CHECK(defaultSquare->getType() == SquareType::wall);
        defaultSquare->setType(SquareType::unmowed);
        CHECK(defaultSquare->getType() == SquareType::unmowed);
        defaultSquare->setType(SquareType::error);
        CHECK(defaultSquare->getType() == SquareType::error);
    }

    delete defaultSquare;
    delete mowedSquare;
    delete unmowedSquare;
    delete wallSquare;
}

TEST_CASE("Lawn Default Constructor Tests") {
    Lawn* test_lawn = new Lawn();

    SUBCASE("Test Lawn initialization") {
        // top wall
        CHECK(test_lawn->getSquare(Coordinates{0,0}).getType() == SquareType::wall);
        CHECK(test_lawn->getSquare(Coordinates{5,0}).getType() == SquareType::wall);
        CHECK(test_lawn->getSquare(Coordinates{9,0}).getType() == SquareType::wall);
        
        // left wall
        CHECK(test_lawn->getSquare(Coordinates{0,1}).getType() == SquareType::wall);
        CHECK(test_lawn->getSquare(Coordinates{0,5}).getType() == SquareType::wall);
        CHECK(test_lawn->getSquare(Coordinates{0,8}).getType() == SquareType::wall);
        
        // right wall
        CHECK(test_lawn->getSquare(Coordinates{9,1}).getType() == SquareType::wall);
        CHECK(test_lawn->getSquare(Coordinates{9,5}).getType() == SquareType::wall);
        CHECK(test_lawn->getSquare(Coordinates{9,8}).getType() == SquareType::wall);

        // unmowed
        CHECK(test_lawn->getSquare(Coordinates{1,1}).getType() == SquareType::unmowed);
        CHECK(test_lawn->getSquare(Coordinates{8,1}).getType() == SquareType::unmowed);
        CHECK(test_lawn->getSquare(Coordinates{5,5}).getType() == SquareType::unmowed);
        CHECK(test_lawn->getSquare(Coordinates{1,8}).getType() == SquareType::unmowed);
        CHECK(test_lawn->getSquare(Coordinates{8,8}).getType() == SquareType::unmowed);
    }

    SUBCASE("Test mowSquare()") {
        test_lawn->mowSquare(Coordinates{1,1});
        test_lawn->mowSquare(Coordinates{2,3});
        test_lawn->mowSquare(Coordinates{4,1});
        test_lawn->mowSquare(Coordinates{7,8});
        test_lawn->mowSquare(Coordinates{8,8});
        // these should not mow the square
        test_lawn->mowSquare(Coordinates{0,0});
        test_lawn->mowSquare(Coordinates{0,9});
        test_lawn->mowSquare(Coordinates{9,0});
        test_lawn->mowSquare(Coordinates{9,9});

        CHECK(test_lawn->getSquare(Coordinates{1,1}).getType() == SquareType::mowed);
        CHECK(test_lawn->getSquare(Coordinates{2,3}).getType() == SquareType::mowed);
        CHECK(test_lawn->getSquare(Coordinates{4,1}).getType() == SquareType::mowed);
        CHECK(test_lawn->getSquare(Coordinates{7,8}).getType() == SquareType::mowed);
        CHECK(test_lawn->getSquare(Coordinates{8,8}).getType() == SquareType::mowed);
        
        CHECK_FALSE(test_lawn->getSquare(Coordinates{0,0}).getType() == SquareType::mowed);
        CHECK_FALSE(test_lawn->getSquare(Coordinates{0,9}).getType() == SquareType::mowed);
        CHECK_FALSE(test_lawn->getSquare(Coordinates{9,0}).getType() == SquareType::mowed);
        CHECK_FALSE(test_lawn->getSquare(Coordinates{9,9}).getType() == SquareType::mowed);
    }


    delete test_lawn;
}

TEST_CASE("Test lawn with set size") {
    // Lawn *test_lawn = new Lawn();
    int width = 15;
    int height = 12;
    Lawn test_lawn(15, 12);

    CHECK(test_lawn.getSquare(Coordinates{0, 0}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{0, (height - 1) / 2}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{0, (height - 1)}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{(width - 1) / 2, 0}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{(width - 1) / 2, (height - 1) / 2}).getType()  == SquareType::unmowed);
    CHECK(test_lawn.getSquare(Coordinates{(width - 1) / 2, (height - 1)}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{(width - 1),0}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{(width - 1), (height - 1) / 2}).getType()  == SquareType::wall);
    CHECK(test_lawn.getSquare(Coordinates{(width - 1), (height - 1)}).getType()  == SquareType::wall);
}


TEST_CASE("Mower constructor test") {
    Lawn test_lawn;

    SUBCASE("Default constructor") {
        Mower test_mower(test_lawn);

        // check stats
        CHECK(test_mower.getPeeks() == 0);
        CHECK(test_mower.getTurns() == 0);
        CHECK(test_mower.getSteps() == 0);

        CHECK(test_mower.getPosition() == Coordinates{1,1});
        CHECK(test_lawn.getSquare(Coordinates{1,1}).getType() == SquareType::mowed);
    }

    SUBCASE("Position constructor") {
        Mower test_mower(test_lawn, Coordinates{2,4});

        // check stats
        CHECK(test_mower.getPeeks() == 0);
        CHECK(test_mower.getTurns() == 0);
        CHECK(test_mower.getSteps() == 0);

        CHECK(test_mower.getPosition() == Coordinates{2,4});
        CHECK(test_lawn.getSquare(Coordinates{2,4}).getType() == SquareType::mowed);
    }

    SUBCASE("Position and facing constructor") {
        Mower test_mower(test_lawn, Coordinates{3,6}, Facing::Direction::west);

        // check stats
        CHECK(test_mower.getPeeks() == 0);
        CHECK(test_mower.getTurns() == 0);
        CHECK(test_mower.getSteps() == 0);

        CHECK(test_mower.getPosition() == Coordinates{3,6});
        CHECK(test_lawn.getSquare(Coordinates{3,6}).getType() == SquareType::mowed);

        // there was a weird bug trying to use the enums direction in CHECK
        // I assume maybe it's related to being in a namespace
        int mdir = test_mower.getFacing();
        int west = Facing::Direction::west;
        CHECK(mdir == west);
    }

    
}

TEST_CASE("Mower control tests") {
    Lawn test_lawn;

    SUBCASE("getFacing(), peek(), turn() test") {
        Mower test_mower(test_lawn);

        // count for north, west, south, east
        int direction_count[4] = {0, 0, 0, 0};
        // count for error, wall, unmowed, mowed
        int square_count[4] = {0, 0, 0, 0};

        for (int i = 0; i < 4; ++i) {
            // get facing and increment direction_count
            Facing::Direction direction = test_mower.getFacing();
            direction_count[static_cast<int>(direction)]++;
            
            // get square and increment square_count
            // also increments peek count
            SquareType square = test_mower.peek();
            square_count[static_cast<int>(square)]++;

            // rotate counterclockwise
            test_mower.turnLeft();
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
        CHECK(test_mower.getPeeks() == 4);
        CHECK(test_mower.getTurns() == 4);
        CHECK(test_mower.getSteps() == 0);
    }

    SUBCASE("getSquare(), forward(), turnLeft(), turnRight(), steps, lawnmowing test") {
        Mower test_mower(test_lawn, Facing::Direction::north);

        // make sure starting square is mowed
        REQUIRE(test_lawn.getSquare(Coordinates{1,1}).getType() == SquareType::mowed);

        // conduct series of moves
        test_mower.forward();        // y++ (1, 2)   steps = 1
        test_mower.forward();        // y++ (1, 3)   steps = 2
        test_mower.turnRight();      // facing east  turns = 1
        test_mower.forward();        // x++ (2, 3)   steps = 3
        test_mower.turnLeft();       // facing north turns = 2
        test_mower.forward();        // y++ (2, 4)   steps = 4

        // check current position
        CHECK(test_mower.getPosition() == Coordinates{2, 4});
        // check last position
        CHECK(test_mower.getLastPosition() == Coordinates{2, 3});

        // check squares that were mowed
        CHECK(test_lawn.getSquare(Coordinates{2, 4}).getType() == SquareType::mowed);
        CHECK(test_lawn.getSquare(Coordinates{2, 3}).getType() == SquareType::mowed);
        CHECK(test_lawn.getSquare(Coordinates{1, 3}).getType() == SquareType::mowed);
        CHECK(test_lawn.getSquare(Coordinates{1, 2}).getType() == SquareType::mowed);
        CHECK(test_lawn.getSquare(Coordinates{1, 1}).getType() == SquareType::mowed);

        // check next square is unmowed
        CHECK(test_mower.peek() == SquareType::unmowed); // peeks = 1

        // check stats
        CHECK(test_mower.getSteps() == 4);
        CHECK(test_mower.getTurns() == 2);  // include turns from reorientation north
        CHECK(test_mower.getPeeks() == 1);
        // CHECK(test_mower.getTotal() == 7 + turns);
    }

    SUBCASE("check if forward() runs into wall") {
        Mower test_mower(test_lawn, Facing::Direction::south);
        
        // check for wall
        REQUIRE(test_mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(test_mower.forward());
        CHECK_FALSE(test_mower.forward());

        // point test_mower west
        test_mower.turnRight();
        // check for wall
        REQUIRE(test_mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(test_mower.forward());
        CHECK_FALSE(test_mower.forward());

        // point test_mower north
        test_mower.turnRight();

        // move north until hit wall
        while (true) {
            if (!test_mower.forward())
                break;
        }
        // check for wall
        REQUIRE(test_mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(test_mower.forward());
        CHECK_FALSE(test_mower.forward());
        // check test_mower position
        CHECK(test_mower.getPosition() == Coordinates{1,8});

        // point test_mower east
        test_mower.turnRight();

        // move east until hit wall
        while (true) {
            if (!test_mower.forward())
                break;
        }
        // check for wall
        REQUIRE(test_mower.peek() == SquareType::wall);
        // check for wall collision
        CHECK_FALSE(test_mower.forward());
        CHECK_FALSE(test_mower.forward());
        // check test_mower position
        CHECK(test_mower.getPosition() == Coordinates{8,8});
    }
}

TEST_CASE("Test mower characters") {
    Lawn test_lawn;
    Mower test_mower(test_lawn, Facing::Direction::north);

    // check all four directions
    CHECK(test_mower.getMowerString().compare("^") == 0);
    test_mower.turnLeft();
    CHECK(test_mower.getMowerString().compare("<") == 0);
    test_mower.turnLeft();
    CHECK(test_mower.getMowerString().compare("v") == 0);
    test_mower.turnLeft();
    CHECK(test_mower.getMowerString().compare(">") == 0);
    test_mower.turnLeft();
    CHECK(test_mower.getMowerString().compare("^") == 0);
}

TEST_CASE("Test LawnDisplay") {
    srand(time(NULL));

    Lawn test_lawn;
    Mower test_mower(test_lawn);
    LawnDisplay test_display(test_lawn, test_mower);

    test_display.draw();
}