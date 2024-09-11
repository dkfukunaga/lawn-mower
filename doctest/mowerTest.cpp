
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
    }
}