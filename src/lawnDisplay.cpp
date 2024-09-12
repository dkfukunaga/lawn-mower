
#include "lawnDisplay.h"

/***** STATIC CONSTANTS *****/

const int LawnDisplay::_default_margin_size = 4;

/***** CONSTRUCTORS *****/

LawnDisplay::LawnDisplay(int margin_size = _default_margin_size) {
    _mower = new Mower();
    _lawn = _mower->getLawn();
    setMarginSize(margin_size);
}

LawnDisplay::LawnDisplay(Mower *mower, int margin_size = _default_margin_size) {
    _mower = mower;
    _lawn = _mower->getLawn();
    setMarginSize(margin_size);
}

LawnDisplay::LawnDisplay(Lawn *lawn, int margin_size = _default_margin_size) {
    _lawn = lawn;
    _mower = new Mower(_lawn);
    setMarginSize(margin_size);
}

/***** GETTERS/ACCESSORS *****/

int LawnDisplay::getMarginSize() { return _margin_size; }

/***** SETTERS/MUTATORS *****/

void LawnDisplay::setMarginSize(int margin_size) {
    _margin_size = margin_size;
    _margin = std::string(_margin_size * 2, ' ');
}

/***** PUBLIC FUNCTIONS *****/



/***** PRIVATE PRINT FUNCTIONS *****/



/***** PRIVATE CURSOR FUNCTIONS *****/

// saves cursor position using ANSI escape code
void LawnDisplay::saveCursorPosition() { std::cout << "\033[s"; }

// restores saved cursor position using ANSI escape code
void LawnDisplay::restoreCursorPosition() { std::cout << "\033[u"; }

// hide cursor in command prompt/terminal
// code generated by ChatGPT
void LawnDisplay::hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// show cursor in command prompt/terminal
// code generated by ChatGPT
void LawnDisplay::showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; // Set cursor visibility to true
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}