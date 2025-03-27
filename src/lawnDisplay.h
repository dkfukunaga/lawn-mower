#pragma once
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "coordinates.h"
#include "square.h"
#include "facing.h"
#include "lawn.h"
#include "mower.h"
#include <iostream>
#include <windows.h>

using LawnPos = Coordinates;

namespace ANSI {
    const std::string           ESC = "\033[";
    const std::string           RESET = ESC + "0m";
    const std::string           WALL = ESC + "37;41m";
    const std::string           GRASS = ESC + "93;41m";
    const std::string           MOWER = ESC + "37;42m";
};


class LawnDisplay {
public:
    LawnDisplay(Lawn &lawn, Mower &mower):
        lawn_(lawn),
        mower_(mower) { };

    void                        draw();
    void                        update();
    void                        drawLawn();
    void                        drawStats();
    void                        drawSquare(LawnPos lawn_pos);
    void                        drawMower();

private:
    Lawn                        &lawn_;
    Mower                       &mower_;
    LawnPos                     last_pos_;

    void                        moveCursor(Coordinates position);
    void                        moveCursor(int x, int y);
    void                        advanceCursor();
    void                        savePosition();
    void                        restorePosition();

    void                        hideCursor();
    void                        showCursor();
};



#endif