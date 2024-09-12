
#include "tester.h"
#include "..\src\lawn.h"


TEST_CASE("Test Lawn object") {
    Lawn test_lawn(10,10);

    SUBCASE("Test Lawn initialization") {
        CHECK(test_lawn.getSquare(Position{0,0}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{0,5}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{0,9}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{5,0}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{5,5}) == SquareType::unmowed);
        CHECK(test_lawn.getSquare(Position{5,9}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{9,0}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{9,5}) == SquareType::wall);
        CHECK(test_lawn.getSquare(Position{9,9}) == SquareType::wall);
    }
    SUBCASE("Test mowSquare()") {
        test_lawn.mowSquare(Position{1,1});
        test_lawn.mowSquare(Position{2,3});
        test_lawn.mowSquare(Position{4,1});
        test_lawn.mowSquare(Position{7,8});
        test_lawn.mowSquare(Position{8,8});
        // these should not mow the square
        test_lawn.mowSquare(Position{0,0});
        test_lawn.mowSquare(Position{0,9});
        test_lawn.mowSquare(Position{9,0});
        test_lawn.mowSquare(Position{9,9});

        CHECK(test_lawn.getSquare(Position{1,1}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(Position{2,3}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(Position{4,1}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(Position{7,8}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(Position{8,8}) == SquareType::mowed);
        
        CHECK_FALSE(test_lawn.getSquare(Position{0,0}) == SquareType::mowed);
        CHECK_FALSE(test_lawn.getSquare(Position{0,9}) == SquareType::mowed);
        CHECK_FALSE(test_lawn.getSquare(Position{9,0}) == SquareType::mowed);
        CHECK_FALSE(test_lawn.getSquare(Position{9,9}) == SquareType::mowed);
    }
}

TEST_CASE("Test lawn with random size") {
    // Lawn *test_lawn = new Lawn();
    Lawn test_lawn;
    int width = test_lawn.getWidth() - 1;
    int height = test_lawn.getHeight() - 1;

    CHECK(test_lawn.getSquare(Position{0, 0}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{0, height / 2}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{0, height}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{width / 2, 0}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{width / 2, height / 2}) == SquareType::unmowed);
    CHECK(test_lawn.getSquare(Position{width / 2, height}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{width,0}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{width, height / 2}) == SquareType::wall);
    CHECK(test_lawn.getSquare(Position{width, height}) == SquareType::wall);
}