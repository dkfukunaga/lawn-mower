

#include "tester.h"
#include "..\src\mowerLogic.h"



TEST_CASE("") {
    Lawn *lawn = new Lawn(12,12);
    Mower *mower = new Mower(lawn);
    LawnDisplay *display = new LawnDisplay(mower);
    MowerLogic *logic = new MowerLogic(display);

    CommandReturn result;

    result = logic->testAlgorithm(Command::peek);

    switch ()

    delete logic;
    delete display;
    delete mower;
    delete lawn;
}

