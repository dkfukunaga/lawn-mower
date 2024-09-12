
#include "tester.h"
#include "..\src\lawn.h"


TEST_CASE("Test Lawn object") {
    Lawn test_lawn(10,10);

    SUBCASE("Test Lawn initialization") {
        CHECK(test_lawn.getSquare(LawnPos{0,0}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{0,5}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{0,9}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{5,0}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{5,5}) == SquareType::unmowed);
        CHECK(test_lawn.getSquare(LawnPos{5,9}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{9,0}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{9,5}) == SquareType::wall);
        CHECK(test_lawn.getSquare(LawnPos{9,9}) == SquareType::wall);
    }
    SUBCASE("Test mowSquare()") {
        test_lawn.mowSquare(LawnPos{1,1});
        test_lawn.mowSquare(LawnPos{2,3});
        test_lawn.mowSquare(LawnPos{4,1});
        test_lawn.mowSquare(LawnPos{7,8});
        test_lawn.mowSquare(LawnPos{8,8});
        // these should not mow the square
        test_lawn.mowSquare(LawnPos{0,0});
        test_lawn.mowSquare(LawnPos{0,9});
        test_lawn.mowSquare(LawnPos{9,0});
        test_lawn.mowSquare(LawnPos{9,9});

        CHECK(test_lawn.getSquare(LawnPos{1,1}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(LawnPos{2,3}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(LawnPos{4,1}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(LawnPos{7,8}) == SquareType::mowed);
        CHECK(test_lawn.getSquare(LawnPos{8,8}) == SquareType::mowed);
        
        CHECK_FALSE(test_lawn.getSquare(LawnPos{0,0}) == SquareType::mowed);
        CHECK_FALSE(test_lawn.getSquare(LawnPos{0,9}) == SquareType::mowed);
        CHECK_FALSE(test_lawn.getSquare(LawnPos{9,0}) == SquareType::mowed);
        CHECK_FALSE(test_lawn.getSquare(LawnPos{9,9}) == SquareType::mowed);
    }
}

TEST_CASE("Test lawn with random size") {
    // Lawn *test_lawn = new Lawn();
    Lawn test_lawn;
    int width = test_lawn.getWidth() - 1;
    int height = test_lawn.getHeight() - 1;

    CHECK(test_lawn.getSquare(LawnPos{0, 0}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{0, height / 2}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{0, height}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{width / 2, 0}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{width / 2, height / 2}) == SquareType::unmowed);
    CHECK(test_lawn.getSquare(LawnPos{width / 2, height}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{width,0}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{width, height / 2}) == SquareType::wall);
    CHECK(test_lawn.getSquare(LawnPos{width, height}) == SquareType::wall);
}