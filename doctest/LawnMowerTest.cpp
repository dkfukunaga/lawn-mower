#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "..\src\square.h"
#include "..\src\coordinates.h"
#include "..\src\facing.h"
#include "..\src\lawn.h"
#include <string>
#include <random>



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
        CHECK(unmowedSquare->getString().find('\"') != std::string::npos);
        CHECK(unmowedSquare->getString().find(',') != std::string::npos);
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
