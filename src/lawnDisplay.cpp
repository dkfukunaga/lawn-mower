
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

void LawnDisplay::moveMower() {
    // save old mower position
    LawnPos old_pos = _mower->getPosition();

    // move mower
    _mower->forward();

    // redraw old square
    drawSquare(old_pos);
    // draw new square
    drawSquare(_mower->getPosition());
}

/***** PRIVATE DRAW FUNCTIONS *****/

void LawnDisplay::drawSquare(LawnPos position) {
    // move to lawn position
    moveCursorToLawnPos(position);

    // check if mower is on the square
    if (_mower->getPosition() == position) {
        // print square string with mower char on left
        printf("%c%c", _mower->getMowerChar(), _mower->getSquare().getString().at(1));
    } else {
        // print square string
        printf("%s", _mower->getSquare().getString());
    }
}

/***** PRIVATE CURSOR FUNCTIONS *****/

// moves cursor to provided position
// (0,0) is the top left corner of the console
void LawnDisplay::moveCursor(Position position) {
    // move cursor using ANSI escape code
    printf("\033[%d;%dH", position.y, position.x);
}

// move cursor by absolute offset using ANSI escape codes
void LawnDisplay::moveCursor(int x, int y) {
    char x_direction = (x > 0 ? 'C' : 'D');
    char y_direction = (y > 0 ? 'A' : 'B');

    if (x != 0)
        printf("\033[%d%c", x, x_direction);
    if (y != 0)
        printf("\033[%d%c", y, y_direction);
}

// moves cursor to provided lawn position
// (0,0) is the top left corner of the console
void LawnDisplay::moveCursorToLawnPos(LawnPos position) {
    // convert lawn position to absolute position
    int x = position.x;
    int y = position.y;

    // adjust for square width
    x = x * _square_dimension[0];

    // adjust for side margin
    x = x + _margin_offsets[0];

    // adjust for lawn y axis being reversed
    y = _mower->getLawn()->getHeight() - y;

    // adjust for top margin, title, and title offset
    // assumes title is 1 line
    y = y + _title_offsets[1] + 1 + _margin_offsets[1];

    // move cursor using ANSI escape code
    printf("\033[%d;%dH", y, x);
}

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
