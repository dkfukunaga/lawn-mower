

#include "lawnDisplay.h"


const int                   LawnDisplay::DEFAULT_MARGINS[2] = {6,3};


LawnDisplay::~LawnDisplay() {
    std::cout << ANSI::reset;
    moveLawnCursor(0, 0);
    std::cout << "\n\n\n" << std::endl;
    if (cursor_hidden_)
        showCursor();
}
void                        LawnDisplay::draw() {
    drawLawn();
    drawStats();
}

void                        LawnDisplay::update() {
    moveLawnCursor(mower_.getLastPosition());
    drawSquare();
    
    moveLawnCursor(mower_.getPosition());
    drawSquare();
    drawMower();
}

void                        LawnDisplay::drawLawn() {
    // clear screen and add top margin
    system("cls");

    for (int i = 0; i < lawn_.getHeight(); ++i) {
        moveLawnCursor(0, i);
        for (int j = 0; j < lawn_.getWidth(); ++j) {
            drawSquare(lawn_.getSquare(j, i));
        }
    }

    drawMower();


}

void                        LawnDisplay::drawStats() {
    
}

void                        LawnDisplay::drawSquare() {
    if (current_pos_ == Coordinates{-1, -1})
        return;
    
    drawSquare(lawn_.getSquare(current_pos_).getType());
}

void                        LawnDisplay::drawSquare(Square square) {
    switch (square.getType()) {
        case SquareType::wall:
            std::cout << ANSI::wall;
            break;
        case SquareType::unmowed:
            std::cout << ANSI::grass;
            break;
        case SquareType::mowed:
            std::cout << ANSI::grass;
            break;
        case SquareType::error:
        default:
            std::cout << ANSI::error;
            break;
    }
    std::cout << square.getString();
}

void                        LawnDisplay::drawSquare(Square square, LawnPos lawn_pos) {
    moveLawnCursor(lawn_pos);
    drawSquare(square);
}

void                        LawnDisplay::drawMower() {
    moveLawnCursor(mower_.getPosition());
    // draw mower character in first char of square, skipping over the second char
    std::cout << ANSI::mower << mower_.getMowerString() << ANSI::advance;
}

void                        LawnDisplay::init() {
    hideCursor();
    cursor_hidden_ = true;

    current_pos_ = mower_.getPosition();

    margins_[0] = DEFAULT_MARGINS[0];
    margins_[1] = DEFAULT_MARGINS[1];
}

void                        LawnDisplay::moveCursor(Coordinates position) {
    std::cout << ANSI::csi << std::to_string(position.y) << ";" << std::to_string(position.x) << "H";
    current_pos_ = Coordinates{-1, -1};
}

void                        LawnDisplay::moveCursor(int x, int y) {
    moveCursor(Coordinates{x, y});
}

void                        LawnDisplay::moveLawnCursor(LawnPos lawn_pos) {
    moveCursor(toCoordinates(lawn_pos));
    current_pos_ = lawn_pos;
}
void                        LawnDisplay::moveLawnCursor(int x, int y) {
    moveLawnCursor(Coordinates{x, y});
}

void                        LawnDisplay::savePosition() {
    std::cout << ANSI::savePos;
}

void                        LawnDisplay::restorePosition() {
    std::cout << ANSI::restorePos;
}

Coordinates                 LawnDisplay::toCoordinates(LawnPos lawn_pos) {
    Coordinates position;
    position.x = margins_[0] + lawn_pos.x * 2;
    position.y = margins_[1] + lawn_.getHeight() - 1 - lawn_pos.y;
    return position;
}

void                        LawnDisplay::hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void                        LawnDisplay::showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; // Set cursor visibility to true
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}




