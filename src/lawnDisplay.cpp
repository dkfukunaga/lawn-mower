

#include "lawnDisplay.h"


const int LawnDisplay::DEFAULT_MARGINS[2] = {6,3};


LawnDisplay::~LawnDisplay() {
    std::cout << ANSI::reset;

    moveCursor(stat_block_pos_.delta(0, 3));
    system("pause");
    
    moveCursor(stat_block_pos_.delta(0, 3));
    std::cout << ANSI::erase_line << std::endl;

    if (cursor_hidden_)
        showCursor();
}
void LawnDisplay::draw() {
    drawLawn();
    drawStats();
}

// call after every mower movement
void LawnDisplay::updateLawn() {
    moveLawnCursor(mower_.getLastPosition());
    drawSquare();
    
    moveLawnCursor(mower_.getPosition());
    drawSquare();
    drawMower();
}

// call after every mower movement and peek
void LawnDisplay::updateStats() {
    bool reset_cursor = false;
    if (!cursor_pos_saved_) {
        savePosition();
        reset_cursor = true;
    }

    moveCursor(stat_mower_pos_);
    std::cout << ANSI::reset << std::setw(stat_mower_pos_width_)
              << positionString();

    moveCursor(stat_peeks_pos_);
    std::cout << std::setw(stat_mower_stats_width_) << std::to_string(mower_.getPeeks());

    moveCursor(stat_turns_pos_);
    std::cout << std::setw(stat_mower_stats_width_) << std::to_string(mower_.getTurns());

    moveCursor(stat_steps_pos_);
    std::cout << std::setw(stat_mower_stats_width_) << std::to_string(mower_.getSteps());

    if (reset_cursor) {
        restorePosition();
    }
}

void LawnDisplay::drawLawn() {
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

void LawnDisplay::drawStats() {
    savePosition();

    moveCursor(stat_block_pos_);
    std::cout << ANSI::reset << "Lawnmower is facing";
    moveCursor(stat_block_pos_.delta(0, 1));
    std::cout << ANSI::reset << "Peeks:       Turns:       Steps:";

    updateStats();

    restorePosition();
}

void LawnDisplay::init() {
    hideCursor();
    cursor_hidden_ = true;

    current_pos_ = mower_.getPosition();

    margins_[0] = DEFAULT_MARGINS[0];
    margins_[1] = DEFAULT_MARGINS[1];

    stat_block_pos_ = Coordinates{margins_[0], 2 * margins_[1] + lawn_.getHeight() - 1};
    stat_mower_pos_ = stat_block_pos_.delta(20, 0);
    stat_peeks_pos_ = stat_block_pos_.delta(7, 1);
    stat_turns_pos_ = stat_block_pos_.delta(20, 1);
    stat_steps_pos_ = stat_block_pos_.delta(33, 1);

    stat_mower_pos_width_ = 20;
    stat_mower_stats_width_ = 4;

    cursor_pos_saved_ = false;

    // set fill to ' ' to overwrite previous text with std::setw
    // and set left justify
    std::cout << std::setfill(' ') << std::left;
}

void LawnDisplay::moveCursor(Coordinates position) {
    std::cout << ANSI::csi << std::to_string(position.y) << ";" << std::to_string(position.x) << "H";
    current_pos_ = Coordinates{-1, -1};
}

void LawnDisplay::moveCursor(int x, int y) {
    moveCursor(Coordinates{x, y});
}

void LawnDisplay::moveLawnCursor(LawnPos lawn_pos) {
    moveCursor(toCoordinates(lawn_pos));
    current_pos_ = lawn_pos;
}
void LawnDisplay::moveLawnCursor(int x, int y) {
    moveLawnCursor(Coordinates{x, y});
}

void LawnDisplay::savePosition() {
    std::cout << ANSI::savePos;
    cursor_pos_saved_ = true;
}

void LawnDisplay::restorePosition() {
    std::cout << ANSI::restorePos;
    cursor_pos_saved_ = false;
}

void LawnDisplay::drawSquare() {
    if (current_pos_ == Coordinates{-1, -1})
        return;
    
    drawSquare(lawn_.getSquare(current_pos_));
}

void LawnDisplay::drawSquare(Square square) {
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

void LawnDisplay::drawSquare(Square square, LawnPos lawn_pos) {
    moveLawnCursor(lawn_pos);
    drawSquare(square);
}

void LawnDisplay::drawMower() {
    moveLawnCursor(mower_.getPosition());
    // draw mower character in first char of square, skipping over the second char
    std::cout << ANSI::mower << mower_.getMowerString() << ANSI::advance;
}

Coordinates                 LawnDisplay::toCoordinates(LawnPos lawn_pos) {
    Coordinates position;
    position.x = margins_[0] + lawn_pos.x * 2;
    position.y = margins_[1] + lawn_.getHeight() - 1 - lawn_pos.y;
    return position;
}

std::string                 LawnDisplay::positionString() {
    return mower_.getFacingString() + " at (" +
           std::to_string(mower_.getPosition().x) + ", " +
           std::to_string(mower_.getPosition().y) + ")";
}

void LawnDisplay::hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void LawnDisplay::showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; // Set cursor visibility to true
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}




