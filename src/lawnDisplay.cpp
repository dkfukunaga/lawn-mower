
#include "lawnDisplay.h"

/***** STATIC CONSTANTS *****/

const std::string LawnDisplay::_title[3] = {
    "   ===========================",
    "-===  Lawn Mower Simulation  ===-",
    "   ==========================="
};

const std::string LawnDisplay::_stats_layout[7] = {
    "+=======+=======+=======+=======+",
    "| Peeks | Turns | Steps | Total |",
    "+-------+-------+-------+-------+",
    "|       |       |       |       |",
    "+-------------------------------+",
    "|     Facing       at   ,       |",
    "+===============================+"
};

/***** CONSTRUCTORS/DESTRUCTORS *****/

// mower full constructor
// takes provided lawn and assigns it to provided mower
LawnDisplay::LawnDisplay(Mower *mower, Lawn *lawn) {
    _lawn = lawn;
    _mower = mower;
    _mower->setLawn(lawn);

    init();
}

// mower constructor
// takes provided mower and its lawn
LawnDisplay::LawnDisplay(Mower *mower) {
    _mower = mower;
    _lawn = _mower->getLawn();

    init();
}

// lawn constructor
// creates new mower and assigns provided lawn
LawnDisplay::LawnDisplay(Lawn *lawn) {
    _lawn = lawn;
    _mower = new Mower(_lawn);

    init();
}

// default constructor
// creates default mower and lawn
LawnDisplay::LawnDisplay() {
    _lawn = new Lawn();
    _mower = new Mower(_lawn);

    init();
}

LawnDisplay::~LawnDisplay() {
    moveToBottom();
    showCursor();
}

/***** GETTERS/ACCESSORS *****/

int         LawnDisplay::getLawnHeight() { return _lawn->getHeight(); }
int         LawnDisplay::getLawnWidth() { return _lawn->getWidth(); }
Square      LawnDisplay::getLawnSquare(LawnPos lawn_pos) {
    return _lawn->getSquare(lawn_pos);
}

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

Direction   LawnDisplay::getMowerFacing() { return _mower->getFacing(); }
LawnPos     LawnDisplay::getMowerLawnPos() { return _mower->getLawnPos(); }
Square      LawnDisplay::getMowerSquare() { return _mower->getSquare(); }
int         LawnDisplay::getMowerPeeks() { return _mower->getPeeks(); }
int         LawnDisplay::getMowerTurns() { return _mower->getTurns(); }
int         LawnDisplay::getMowerSteps() { return _mower->getSteps(); }
int         LawnDisplay::getMowerTotal() { return _mower->getTotal(); }

/***** PUBLIC DISPLAY FUNCTIONS *****/

void LawnDisplay::drawScreen() {
    // clear console
    system("cls");
    
    // calculate section margins
    int title_margin = _margin_offsets[0] + _title_offsets[0];
    int lawn_margin = _margin_offsets[0] + _lawn_offsets[0];
    int stats_margin = _margin_offsets[0] + _stats_offsets[0];

    // draw sections
    drawTitle(title_margin);
    drawLawn(lawn_margin);
    drawStats(stats_margin);

    // // skip top margin
    // for (int i = 0; i < _margin_offsets[1]; ++i)
    //     printf("\n");
    
    
    // // create side margin string
    // std::string left_margin(_margin_offsets[0], ' ');
    
    // // create title_margin
    // std::string title_margin = left_margin + std::string(_title_offsets[0], ' ');

    // // draw title
    // printf("%s%s\n", title_margin.c_str(), _title.c_str());

    // // skip lawn offset
    // for (int i = 0; i < _lawn_offsets[1]; ++i)
    //     printf("\n");

    // // create lawn_margin
    // std::string lawn_margin = left_margin + std::string(_lawn_offsets[0], ' ');
    
    // // draw lawn
    // // loop through rows
    // for (int lawn_y = _mower->getLawn()->getHeight() - 1; lawn_y >= 0; --lawn_y) {
    //     // skip margin
    //     printf("%s", lawn_margin.c_str());
    //     // loop through columns
    //     for (int lawn_x = 0; lawn_x < _mower->getLawn()->getWidth(); ++lawn_x) {
    //         drawSquare(LawnPos(lawn_x, lawn_y));
    //     }
    //     printf("\n");
    // }

    // // skip stats offset
    // for (int i = 0; i < _stats_offsets[1]; ++i)
    //     printf("\n");

    // // create stats_margin
    // std::string stats_margin = left_margin + std::string(_stats_offsets[0], ' ');
    
    // // print stats
    // printf("%s[MOWER STATS GO HERE]\n", stats_margin.c_str());

    // // skip bottom margin
    // for (int i = 0; i < _margin_offsets[1]; ++i)
    //     printf("\n");
        
}

void LawnDisplay::moveToBottom() {
    moveCursor(_bottom_pos);
}

SquareType LawnDisplay::mowerPeek() {
    SquareType temp = _mower->peek();
    updateMowerPeeks();
    return temp;
}

bool LawnDisplay::mowerForward() {
    // save old mower position
    LawnPos old_pos = _mower->getLawnPos();

    // move 
    bool moved = _mower->forward();
    updateMowerSteps();
    if (moved) {
        // redraw old square
        drawSquare(old_pos);
        // draw new square
        drawSquare(_mower->getLawnPos());
        // update position
        updateMowerPosition();
        return true;
    } else {
        return false;
    }
}

void LawnDisplay::mowerTurnLeft() {
    _mower->turnLeft();
    drawSquare(_mower->getLawnPos());
    updateMowerTurns();
    updateMowerPosition();
}

void LawnDisplay::mowerTurnRight() {
    _mower->turnRight();
    drawSquare(_mower->getLawnPos());
    updateMowerTurns();
    updateMowerPosition();
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

void LawnDisplay::drawTitle(int margin) {

    // move cursor down
    // don't change x position because done in loop
    moveCursor(0, _margin_offsets[1] + _title_offsets[1]);

    int left_margin = _margin_offsets[0] + _title_offsets[0];

    // loop through title rows
    for (int i = 0; i < _title_height; ++i) {
        moveCursor(left_margin, 0);
        printf("%s\n", _title[i].c_str());
    }
}

void LawnDisplay::drawLawn(int margin) {

    // move cursor down
    // don't change x position because done by drawSquare
    moveCursor(0, _lawn_offsets[1]);

    // calculate left margin
    int left_margin = _margin_offsets[0] + _lawn_offsets[0];

    // loop through rows
    for (int lawn_y = _mower->getLawn()->getHeight() - 1; lawn_y >= 0; --lawn_y) {
        // loop through columns
        for (int lawn_x = 0; lawn_x < _mower->getLawn()->getWidth(); ++lawn_x) {
            drawSquare(LawnPos(lawn_x, lawn_y));
        }
        printf("\n");
    }
    
}

void LawnDisplay::drawStats(int margin) {

    // move cursor down
    // don't change x position because done in loop
    moveCursor(0, _stats_offsets[1]);

    int left_margin = _margin_offsets[0] + _stats_offsets[0];

    // loop through stats rows
    for (int i = 0; i < _stats_height; ++i) {
        moveCursor(left_margin, 0);
        printf("%s\n", _stats_layout[i].c_str());
    }

    updateMowerPeeks();
    updateMowerTurns();
    updateMowerSteps();
    updateMowerTotal();
    updateMowerPosition();

    // move cursor to bottom of display
    moveCursor(0, _margin_offsets[1]);

}

void LawnDisplay::updateMowerPeeks() {
    moveCursor(_peeks_pos);
    printf("%3d", _mower->getPeeks());
    updateMowerTotal();
}

void LawnDisplay::updateMowerTurns() {
    moveCursor(_turns_pos);
    printf("%3d", _mower->getTurns());
    updateMowerTotal();
}

void LawnDisplay::updateMowerSteps() {
    moveCursor(_steps_pos);
    printf("%3d", _mower->getSteps());
    updateMowerTotal();
}

void LawnDisplay::updateMowerTotal() {
    moveCursor(_total_pos);
    printf("%3d", _mower->getTotal());
}

void LawnDisplay::updateMowerPosition() {
    // update direction
    moveCursor(_mower_dir_pos);
    printf("%-5s", getDirectionString(_mower->getFacing(), LetterCase::upper).c_str());

    // update x,y coordinates
    moveCursor(_mower_x_pos);
    printf("%2d", _mower->getLawnPos().getX());
    moveCursor(_mower_y_pos);
    printf("%-2d", _mower->getLawnPos().getY());
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
    char y_direction = (y > 0 ? 'B' : 'A');
    if (x < 0) 
        x *= -1;
    if (y < 0)
        y *= -1;

    if (x != 0)
        printf("\033[%d%c", x - 1, x_direction);
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
    x = x + _margin_offsets[0] + _lawn_offsets[0];

    // adjust for lawn y axis being reversed
    y = _mower->getLawn()->getHeight() - y;

    // adjust for top margin, title offset, title, lawn offset
    // assumes title is 1 line
    y = y + _margin_offsets[1] + _title_height + _title_offsets[1] + _lawn_offsets[1];

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
    // calculate bottom of display to move cursor before quitting
    int bottom_y = _margin_offsets[1] + _title_offsets[1] + _title_height +
                   _lawn_offsets[1] + _mower->getLawn()->getHeight() +
                   _stats_offsets[1] + _stats_height + _margin_offsets[1];

    _bottom_pos.set(0, bottom_y);

    // calculate y position of stats data
    int stats_pos_y = _margin_offsets[1] + _title_offsets[1] + _title_height +
                      _lawn_offsets[1] + _mower->getLawn()->getHeight() +
                      _stats_offsets[1] + 4;

    // calculate x position of first stat
    int stats_pos_x = _margin_offsets[0] + _stats_offsets[0];

    // set all stats positions, using x relative to stats_pos_x
    _peeks_pos     = Position(stats_pos_x +  3, stats_pos_y);
    _turns_pos     = Position(stats_pos_x + 11, stats_pos_y);
    _steps_pos     = Position(stats_pos_x + 19, stats_pos_y);
    _total_pos     = Position(stats_pos_x + 27, stats_pos_y);
    _mower_dir_pos = Position(stats_pos_x + 13, stats_pos_y + 2);
    _mower_x_pos   = Position(stats_pos_x + 22, stats_pos_y + 2);
    _mower_y_pos   = Position(stats_pos_x + 25, stats_pos_y + 2);

    // hide cursor
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
