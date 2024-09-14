
#include "lawnDisplay.h"

/***** STATIC CONSTANTS *****/


/***** CONSTRUCTORS/DESTRUCTORS *****/

// default constructor
// creates default mower and lawn
LawnDisplay::LawnDisplay() {
    _mower = new Mower();

    init();
}

// mower constructor
// takes provided mower and its lawn
LawnDisplay::LawnDisplay(Mower *mower) {
    _mower = mower;

    init();
}

// lawn constructor
// creates new mower and assigns provided lawn
LawnDisplay::LawnDisplay(Lawn *lawn) {
    _mower = new Mower;
    _mower->setLawn(lawn);

    init();
}

LawnDisplay::~LawnDisplay() {
    moveToBottom();
    showCursor();
    delete _mower;
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

/***** PUBLIC DISPLAY FUNCTIONS *****/

void LawnDisplay::drawScreen() {
    // clear console
    system("cls");

    // skip top margin
    for (int i = 0; i < _margin_offsets[1]; ++i)
        printf("\n");
    
    // create side margin string
    std::string left_margin(_margin_offsets[0], ' ');
    
    // creat title_margin
    std::string title_margin = left_margin + std::string(_title_offsets[0], ' ');

    // draw title
    printf("%s%s\n", title_margin.c_str(), _title.c_str());

    // skip lawn offset
    for (int i = 0; i < _lawn_offsets[1]; ++i)
        printf("\n");

    // create lawn_margin
    std::string lawn_margin = left_margin + std::string(_lawn_offsets[0], ' ');
    
    // draw lawn
    // loop through rows
    for (int lawn_y = _mower->getLawn()->getHeight() - 1; lawn_y >= 0; --lawn_y) {
        // skip margin
        printf("%s", lawn_margin.c_str());
        // loop through columns
        for (int lawn_x = 0; lawn_x < _mower->getLawn()->getWidth(); ++lawn_x) {
            drawSquare(LawnPos(lawn_x, lawn_y));
        }
        printf("\n");
    }

    // skip stats offset
    for (int i = 0; i < _stats_offsets[1]; ++i)
        printf("\n");

    // create stats_margin
    std::string stats_margin = left_margin + std::string(_stats_offsets[0], ' ');
    
    // print stats
    printf("%s[MOWER STATS GO HERE]\n", stats_margin.c_str());

    // skip bottom margin
    for (int i = 0; i < _margin_offsets[1]; ++i)
        printf("\n");
        
}

void LawnDisplay::moveToBottom() {
    moveCursor(_bottom_pos);
}

SquareType LawnDisplay::mowerPeek() {
    return _mower->peek();
}

void LawnDisplay::mowerForward() {
    // save old mower position
    LawnPos old_pos = _mower->getLawnPos();

    // move mower
    _mower->forward();

    // redraw old square
    drawSquare(old_pos);
    // draw new square
    drawSquare(_mower->getLawnPos());
}

void LawnDisplay::mowerTurnLeft() {
    _mower->turnLeft();
    drawSquare(_mower->getLawnPos());
}

void LawnDisplay::mowerTurnRight() {
    _mower->turnRight();
    drawSquare(_mower->getLawnPos());
}

/***** PRIVATE DRAW FUNCTIONS *****/

// void LawnDisplay::drawSquare() {
//     // check if mower is on the square
//     if (_mower->getLawnPos() == convertToLawnPos(_position)) {
//         // print square string with mower char on left
//         printf("%c%c", _mower->getMowerChar(), _mower->getSquare().getString().at(1));
//     } else {
//         // print square string
//         printf("%s", _mower->getSquare().getString());
//     }
// }

void LawnDisplay::drawSquare(LawnPos lawn_pos) {
    // move to lawn position
    moveCursorToLawnPos(lawn_pos);

    // check if mower is on the square
    if (_mower->getLawnPos() == lawn_pos) {
        // print square string with mower char on left
        printf("%c%c", _mower->getMowerChar(), _mower->getLawn()->getSquare(lawn_pos).getString().at(1));
    } else {
        // print square string
        printf("%s", _mower->getLawn()->getSquare(lawn_pos).getString().c_str());
    }
}

/***** PRIVATE CURSOR FUNCTIONS *****/

// moves cursor to provided position
// (0,0) is the top left corner of the console
void LawnDisplay::moveCursor(Position position) {
    // move cursor using ANSI escape code
    printf("\033[%d;%dH", position.getY(), position.getX());
}

// move cursor by absolute offset using ANSI escape codes
void LawnDisplay::moveCursor(int x, int y) {
    char x_direction = (x > 0 ? 'C' : 'D');
    char y_direction = (y > 0 ? 'A' : 'B');
    if (x < 0) 
        x *= -1;
    if (y < 0)
        y *= -1;

    if (x != 0)
        printf("\033[%d%c", x, x_direction);
    if (y != 0)
        printf("\033[%d%c", y, y_direction);
}

// moves cursor to provided lawn position
// (0,0) is the top left corner of the console
void LawnDisplay::moveCursorToLawnPos(LawnPos lawn_pos) {
    // convert lawn position to absolute position
    int x = lawn_pos.getX();
    int y = lawn_pos.getY();

    // adjust for square width
    x = x * _square_dimension[0];

    // adjust for side margin
    x = x + _margin_offsets[0];

    // adjust for lawn y axis being reversed
    y = _mower->getLawn()->getHeight() - y;

    // adjust for top margin, title, and title offset
    // assumes title is 1 line
    y = y + _margin_offsets[1] + _title_offsets[1] + _title_height;

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


void LawnDisplay::init() {
    int bottom_y = _margin_offsets[1] + _title_height + _title_offsets[1] +
                   _lawn_offsets[1] + _mower->getLawn()->getHeight() +
                   _stats_offsets[1] + _stats_height + _margin_offsets[1];

    _bottom_pos.set(0, bottom_y);

    hideCursor();
}



// LawnPos LawnDisplay::convertToLawnPos(Position position) {
//     // check lawn bounds
//     int lawn_left = _margin_offsets[0] + _lawn_offsets[0];
//     int lawn_right = lawn_left + 2 * _mower->getLawn()->getWidth();
//     int lawn_top = _margin_offsets[1] + _title_offsets[1] + _lawn_offsets[1] + 1;
//     int lawn_bottom = lawn_top + _mower->getLawn()->getHeight();
//     if (position.getX() < lawn_left || position.getX() > lawn_right ||
//         position.getY() < lawn_top  || position.getY() > lawn_bottom) {
//         return LawnPos(-1, -1); // indicate error
//     }

//     // convert to lawnPos
//     int lawn_x = (position.getX() - lawn_left) / 2;
//     int lawn_y = position.getY() - lawn_top;

//     return LawnPos(lawn_x, lawn_y);
// }
