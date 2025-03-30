
#include "lawnDriver.h"


void LawnDriver::start() {
    display_->draw();
}

SquareType LawnDriver::peek() {
    Sleep(delay_);
    SquareType peeked = mower_.peek();
    display_->updateStats();
    return peeked;
}

void LawnDriver::forward() {
    mower_.forward();
    display_->updateLawn();
    display_->updateStats();
    Sleep(delay_);
}

void LawnDriver::turnRight() {
    mower_.turnRight();
    display_->updateLawn();
    display_->updateStats();
    Sleep(delay_);
}

void LawnDriver::turnLeft() {
    mower_.turnLeft();
    display_->updateLawn();
    display_->updateStats();
    Sleep(delay_);
}



