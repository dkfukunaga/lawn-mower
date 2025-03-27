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
    inline const std::string    esc = "\033";               // ESC key
    inline const std::string    csi = esc + "[";            // Control Sequence Introducer

    inline const std::string    advance = csi + "1C";       // forward one character
    inline const std::string    savePos = csi + "s";        // save curent cursor position
    inline const std::string    restorePos = csi + "u";     // restore saved cursor position

    inline const std::string    reset = csi + "0m";
    inline const std::string    wall = csi + "37;41m";      // white on red
    inline const std::string    grass = csi + "93;41m";     // bright yellow on green
    inline const std::string    mower = csi + "30;42m";     // black on green
    inline const std::string    error = csi + "31;103m";    // red on bright yellow
};


class LawnDisplay {
public:
    LawnDisplay(Lawn &lawn, Mower &mower):
        lawn_(lawn),
        mower_(mower) {
            init();
        };
    ~LawnDisplay();

    void                        draw();
    void                        update();
    void                        drawLawn();
    void                        drawStats();
    void                        drawSquare(Square square);
    void                        drawSquare(Square square, LawnPos lawn_pos);
    void                        drawMower();

private:
    Lawn&                       lawn_;
    Mower&                      mower_;
    LawnPos                     last_pos_;
    bool                        cursor_hidden_;
    int                         margins_[2];

    static const int            DEFAULT_MARGINS[2];

    void                        init();
    void                        moveCursor(Coordinates position);
    void                        moveLawnCursor(LawnPos lawn_pos);
    void                        savePosition();
    void                        restorePosition();

    Coordinates                 toCoordinates(LawnPos lawn_pos);

    void                        hideCursor();
    void                        showCursor();
};



#endif