#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "..\src\lawn.h"


TEST_CASE("Test Lawn object") {
    Lawn test_lawn(10,10);

    SUBCASE("Test Lawn initialization") {
        CHECK(test_lawn.getSquare(Position{0,0}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{0,5}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{0,9}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{5,0}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{5,5}) == Square::unmowed);
        CHECK(test_lawn.getSquare(Position{5,9}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{9,0}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{9,5}) == Square::wall);
        CHECK(test_lawn.getSquare(Position{9,9}) == Square::wall);
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

        CHECK(test_lawn.getSquare(Position{1,1}) == Square::mowed);
        CHECK(test_lawn.getSquare(Position{2,3}) == Square::mowed);
        CHECK(test_lawn.getSquare(Position{4,1}) == Square::mowed);
        CHECK(test_lawn.getSquare(Position{7,8}) == Square::mowed);
        CHECK(test_lawn.getSquare(Position{8,8}) == Square::mowed);
        
        CHECK_FALSE(test_lawn.getSquare(Position{0,0}) == Square::mowed);
        CHECK_FALSE(test_lawn.getSquare(Position{0,9}) == Square::mowed);
        CHECK_FALSE(test_lawn.getSquare(Position{9,0}) == Square::mowed);
        CHECK_FALSE(test_lawn.getSquare(Position{9,9}) == Square::mowed);
    }
}