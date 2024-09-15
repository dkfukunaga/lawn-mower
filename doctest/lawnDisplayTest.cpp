

#include "tester.h"
#include "..\src\lawnDisplay.h"

TEST_CASE("Test mower and lawn getters") {
    Lawn *lawn = new Lawn(14,12);
    Mower *mower = new Mower(lawn);
    LawnDisplay *display = new LawnDisplay(mower, lawn);
    display->drawScreen();

    CHECK(display->getLawnHeight() == 12);
    CHECK(display->getLawnWidth() == 14);
    CHECK(display->getLawnSquare(LawnPos(0,0)).getType() == SquareType::wall);
    CHECK(display->getLawnSquare(LawnPos(1,1)).getType() == SquareType::mowed);
    CHECK(display->getLawnSquare(LawnPos(1,2)).getType() == SquareType::unmowed);

    int turn_counter = 0;
    SquareType next;

    // orient north
    while (mower->getFacing() != Direction::north) {
        display->mowerTurnLeft();
        turn_counter++;
    }
    next = display->mowerPeek();
    
    CHECK(next == SquareType::unmowed);
    CHECK(display->getMowerFacing() == Direction::north);
    CHECK(display->getMowerLawnPos().getX() == 1);
    CHECK(display->getMowerLawnPos().getY() == 1);
    CHECK(display->getMowerSquare().getType() == SquareType::mowed);
    CHECK(display->getMowerPeeks() == 1);
    CHECK(display->getMowerTurns() == turn_counter);

    display->mowerTurnLeft();
    next = display->mowerPeek();

    CHECK(next == SquareType::wall);
    CHECK(display->getMowerFacing() == Direction::west);
    CHECK(display->getMowerPeeks() == 2);
    CHECK(display->getMowerTurns() == turn_counter + 1);
 
    display->mowerTurnRight();
    display->mowerForward();
    display->mowerForward();

    CHECK(display->getMowerSquare().getType() == SquareType::mowed);
    CHECK(display->getMowerLawnPos().getX() == 1);
    CHECK(display->getMowerLawnPos().getY() == 3);
    CHECK(display->getMowerPeeks() == 2);
    CHECK(display->getMowerTurns() == turn_counter + 2);
    CHECK(display->getMowerSteps() == 2);
    CHECK(display->getMowerTotal() == turn_counter + 6);


    delete display;
}