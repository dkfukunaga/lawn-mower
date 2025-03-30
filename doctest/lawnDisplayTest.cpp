

#include "..\src\square.h"
#include "..\src\coordinates.h"
#include "..\src\facing.h"
#include "..\src\lawn.h"
#include "..\src\mower.h"
#include "..\src\lawnDisplay.h"
#include "..\src\lawnDriver.h"
#include <iostream>
#include <memory>
#include <random>
#include <time.h>

int main() {

    srand(time(NULL));

    std::unique_ptr<Lawn> test_lawn = std::make_unique<Lawn>();
    std::unique_ptr<Mower> test_mower = std::make_unique<Mower>(*test_lawn, Facing::Direction::north);
    std::unique_ptr<LawnDriver> test_driver = std::make_unique<LawnDriver>(*test_lawn, *test_mower, 250);

    test_driver->start();

    test_driver->peek();
    for (int i = 0; i < 7; ++i)
        test_driver->forward();
    test_driver->turnRight();
    for (int i = 0; i < 7; ++i)
        test_driver->forward();
    test_driver->turnRight();
    test_driver->forward();
    test_driver->turnRight();
    for (int i = 0; i < 6; ++i)
        test_driver->forward();
    test_driver->turnLeft();
    test_driver->peek();

    return 0;
}
