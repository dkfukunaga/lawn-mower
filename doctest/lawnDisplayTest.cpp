

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

    int delay = 250;
    
    Sleep(delay);
    test_mower.peek();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.turnRight();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.turnRight();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.turnRight();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();
    
    Sleep(delay);
    test_mower.forward();
    test_display->updateLawn();
    test_display->updateStats();

    delete test_display;

    return 0;
}
