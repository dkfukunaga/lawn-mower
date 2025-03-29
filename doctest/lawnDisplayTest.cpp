

#include "..\src\square.h"
#include "..\src\coordinates.h"
#include "..\src\facing.h"
#include "..\src\lawn.h"
#include "..\src\mower.h"
#include "..\src\lawnDisplay.h"
#include <iostream>
#include <random>
#include <time.h>

int main() {

    srand(time(NULL));

    Lawn test_lawn;
    Mower test_mower(test_lawn);
    LawnDisplay* test_display = new LawnDisplay(test_lawn, test_mower);

    test_display->draw();
    
    Sleep(100);
    test_mower.forward();
    test_display->update();
    
    Sleep(100);
    test_mower.turnRight();
    test_mower.forward();
    test_display->update();
    
    Sleep(100);
    test_mower.turnRight();
    test_mower.forward();
    test_display->update();
    
    Sleep(100);
    test_mower.turnRight();
    test_mower.forward();
    test_display->update();

    delete test_display;

    return 0;
}
