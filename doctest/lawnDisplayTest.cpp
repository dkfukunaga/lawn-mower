
// #include "tester.h"
// #include "..\src\lawnDisplay.h"

// TEST_CASE("Test default margin and offsets") {
    
// }

#include "..\src\lawnDisplay.h"
#include <conio.h>

void wait(LawnDisplay *lawn_display);
void quit(LawnDisplay *lawn_display);

int main() {

    srand(time(NULL));

    Lawn *lawn = new Lawn(15,12);

    LawnDisplay *lawn_display = new LawnDisplay(lawn);
    lawn_display->drawScreen();

    while(lawn_display->mowerPeek() == SquareType::wall) {
        wait(lawn_display);
        lawn_display->mowerTurnRight();
    }
    
    for (int i = 0; i < 3; ++i) {
        wait(lawn_display);
        lawn_display->mowerForward();
    }

    wait(lawn_display);
    lawn_display->mowerTurnRight();

    bool turn_left = false;

    wait(lawn_display);
    if (!lawn_display->mowerForward()) {
        turn_left = true;
        wait(lawn_display);
        lawn_display->mowerTurnLeft();
        wait(lawn_display);
        lawn_display->mowerTurnLeft();
        wait(lawn_display);
        lawn_display->mowerForward();
    }
    wait(lawn_display);
    lawn_display->mowerForward();

    wait(lawn_display);
    if (turn_left)
        lawn_display->mowerTurnLeft();
    else
        lawn_display->mowerTurnRight();

    for (int i = 0; i < 3; ++i) {
        wait(lawn_display);
        lawn_display->mowerForward();
    }

    wait(lawn_display);
    if (turn_left)
        lawn_display->mowerTurnLeft();
    else
        lawn_display->mowerTurnRight();

    wait(lawn_display);
    lawn_display->mowerForward();

    wait(lawn_display);
    if (turn_left)
        lawn_display->mowerTurnLeft();
    else
        lawn_display->mowerTurnRight();

    for (int i = 0; i < 3; ++i) {
        wait(lawn_display);
        lawn_display->mowerForward();
    }
    wait(lawn_display);

    // delete lawn;

    quit(lawn_display);

    // system("cls");
    // printf("\n\n");
    // for (int i = 1; i <= 10; ++i)
    //     printf("test %2d: %s, %c\n", i, "####", static_cast<char>(96 + i));
    
    // // system("pause");
    //     // std::cout << "\033[1A";
    // printf("Press any key...");
    // getch();

    // for (int i = 11; i <= 20; ++i) {
    //     // std::cout << "\033[2A";

    //     printf("\033[%d%ctest %2d: %s\033[4C%c\n", 2, 'A', i, "&&", static_cast<char>(96 + i));
    // }

    // printf("\033[11B");

    return 0;
}

void wait(LawnDisplay *lawn_display) {
    char c = getch();
    if (c == 'q')
        quit(lawn_display);
}

void quit(LawnDisplay *lawn_display) {
    // lawn_display->moveToBottom();
    delete lawn_display;
    exit(0);
}