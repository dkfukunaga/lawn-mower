#pragma once
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "coordinates.h"
#include "square.h"
#include "facing.h"
#include "lawn.h"
#include "mower.h"
#include <iostream>
#include <iomanip>
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
    inline const std::string    grass = csi + "93;42m";     // bright yellow on green
    inline const std::string    mower = csi + "30;42m";     // black on green
    inline const std::string    error = csi + "31;103m";    // red on bright yellow

    inline const std::string    erase_line = csi + "2K";    // erase entire line
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
    void                        updateLawn();
    void                        updateStats();

private:
    Lawn&                       lawn_;
    Mower&                      mower_;
    LawnPos                     current_pos_;
    Coordinates                 stat_block_pos_;
    Coordinates                 stat_mower_pos_;
    Coordinates                 stat_peeks_pos_;
    Coordinates                 stat_turns_pos_;
    Coordinates                 stat_steps_pos_;
    int                         stat_mower_pos_width_;
    int                         stat_mower_stats_width_;
    bool                        cursor_pos_saved_;
    bool                        cursor_hidden_;
    int                         margins_[2];

    static const int            DEFAULT_MARGINS[2];

    void                        init();
    void                        moveCursor(Coordinates position);
    void                        moveCursor(int x, int y);
    void                        moveLawnCursor(LawnPos lawn_pos);
    void                        moveLawnCursor(int x, int y);
    void                        savePosition();
    void                        restorePosition();
    
    void                        drawLawn();
    void                        drawStats();
    void                        drawSquare();
    void                        drawSquare(Square square);
    void                        drawSquare(Square square, LawnPos lawn_pos);
    void                        drawMower();

    Coordinates                 toCoordinates(LawnPos lawn_pos);
    std::string                 positionString();

    void                        hideCursor();
    void                        showCursor();
};



#endif