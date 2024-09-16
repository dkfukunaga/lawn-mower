
#include "tester.h"
#include "..\src\lawnPos.h"






TEST_CASE("Test north(), west(), south(), east()") {
    // check that they return the correct position and don't move position
    LawnPos lawn_pos(5, 5);

    REQUIRE(lawn_pos.x == 5);
    REQUIRE(lawn_pos.y == 5);

    // test north()
    CHECK(lawn_pos.north().x == 5);
    CHECK(lawn_pos.north().y == 6);
    CHECK(lawn_pos.x == 5);
    CHECK(lawn_pos.y == 5);

    // test west()
    CHECK(lawn_pos.west().x == 4);
    CHECK(lawn_pos.west().y == 5);
    CHECK(lawn_pos.x == 5);
    CHECK(lawn_pos.y == 5);

    // test south()
    CHECK(lawn_pos.south().x == 5);
    CHECK(lawn_pos.south().y == 4);
    CHECK(lawn_pos.x == 5);
    CHECK(lawn_pos.y == 5);

    // test east()
    CHECK(lawn_pos.east().x == 6);
    CHECK(lawn_pos.east().y == 5);
    CHECK(lawn_pos.x == 5);
    CHECK(lawn_pos.y == 5);
}