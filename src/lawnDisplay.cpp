
#include "lawnDisplay.h"

/***** STATIC CONSTANTS *****/

const std::string LawnDisplay::_title = "Lawn Mower Simulation";

/***** CONSTRUCTORS *****/

// default constructor
// creates default mower and lawn
LawnDisplay::LawnDisplay() {
    _mower = new Mower();
}

// mower constructor
// takes provided mower and its lawn
LawnDisplay::LawnDisplay(Mower *mower) {
    _mower = mower;
}

// lawn constructor
// creates new mower and assigns provided lawn
LawnDisplay::LawnDisplay(Lawn *lawn) {
    _mower = new Mower;
    _mower->setLawn(lawn);
}

/***** GETTERS/ACCESSORS *****/

// returns array of x and y margin offsets
int* LawnDisplay::getMarginOffsets() { return _margin_offsets; }

// returns array of x and y title offsets from inside the margins
int* LawnDisplay::getTitleOffsets() { return _title_offsets; }

// returns array of x and y lawn offsets from inside the margin
// and relative to the bottom of the title
int* LawnDisplay::getLawnOffsets() { return _lawn_offsets; }

// returns array of x and y stats offsets from inside the margin
// and relative to the bottom of the lawn
int* LawnDisplay::getStatsOffsets() { return _stats_offsets; }
LawnPos LawnDisplay::getLawnPosition() {
    // adjust for side margin
    int x = (_cursor_position.x - _margin_offsets[0]);

    // adjust for square width
    x = x / _square_dimension[0];

    // adjust for top margin, title, and title offset
    // assumes title is 1 line
    int y = _cursor_position.y - _margin_offsets[1] - _title_offsets[1] - 1;

    // adjust for lawn y axis being reversed
    y = _mower->getLawn()->getHeight() - y;

    return LawnPos(x, y);
}

/***** SETTERS/MUTATORS *****/

// set margin offsets from top and left side of console
void LawnDisplay::setMarginOffsets(int x_margin,int  y_margin) {
    _margin_offsets[0] = x_margin;
    _margin_offsets[1] = y_margin;
}

// set title offsets from border, border
void LawnDisplay::setTitleOffsets(int x_margin,int  y_margin) {
    _title_offsets[0] = x_margin;
    _title_offsets[1] = y_margin;
}

// set lawn offsets from border, title
void LawnDisplay::setLawnOffsets(int x_margin,int  y_margin) {
    _lawn_offsets[0] = x_margin;
    _lawn_offsets[1] = y_margin;
}

// set stats offsets from border, lawn
void LawnDisplay::setStatsOffsets(int x_margin,int  y_margin) {
    _stats_offsets[0] = x_margin;
    _stats_offsets[1] = y_margin;
}

/***** PUBLIC FUNCTIONS *****/



/***** PRIVATE PRFUNCTIONS *****/



/***** PRIVATE CURSOR FUNCTIONS *****/

// moves cursor to provided position
// (0,0) is the top left corner of the console
void LawnDisplay::moveCursor(Position position) {
    std::cout << "\033[" << std::to_string(position.y) << ";"
              << std::to_string(position.x) << "H";
}

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

/***** PRIVATE HELPER FUNCTIONS *****/

// convert a Lawn position into the absolute position in the console
// returns Position
Position LawnDisplay::convertLawnPosition(LawnPos lawn_position) {
    int x = lawn_position.x;
    int y = lawn_position.y;

    // adjust for square width
    x = x * _square_dimension[0];

    // adjust for side margin
    x = x + _margin_offsets[0];

    // adjust for lawn y axis being reversed
    y = _mower->getLawn()->getHeight() - y;

    // adjust for top margin, title, and title offset
    // assumes title is 1 line
    y = y + _title_offsets[1] + 1 + _margin_offsets[1];

    return Position(x, y);
}