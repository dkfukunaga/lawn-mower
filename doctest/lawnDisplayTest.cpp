
// #include "tester.h"
// #include "..\src\lawnDisplay.h"

// TEST_CASE("Test default margin and offsets") {
    
// }

#include "..\src\lawnDisplay.h"
#include <conio.h>

int main() {

    srand(time(NULL));

    Lawn *lawn = new Lawn(15,12);

    LawnDisplay lawn_display(lawn);
    lawn_display.drawScreen();

    delete lawn;

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