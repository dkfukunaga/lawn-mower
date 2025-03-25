#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "..\src\square.h"
#include <string>

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
        
    }

    delete defaultSquare;
    delete mowedSquare;
    delete unmowedSquare;
    delete wallSquare;
}
