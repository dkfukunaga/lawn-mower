#pragma once
#ifndef LAWN_DRIVER_H
#define LAWN_DRIVER_H


#include "facing.h"
#include "coordinates.h"
#include "square.h"
#include "lawn.h"
#include "mower.h"
#include "lawnDisplay.h"
#include <memory>
#include <windows.h>


class LawnDriver {
public:
    LawnDriver(Lawn& lawn, Mower& mower, int delay = 100):
    lawn_(lawn),
    mower_(mower),
    delay_(delay) {
        display_ = std::make_unique<LawnDisplay>(lawn_, mower_);
    }

    void                            start();
    SquareType                      peek();
    void                            forward();
    void                            turnRight();
    void                            turnLeft();
private:
    Lawn&                           lawn_;
    Mower&                          mower_;
    std::unique_ptr<LawnDisplay>    display_;
    int                             delay_;
};



#endif