
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "common.h"
#include "lawn.h"
#include "mower.h"
#include <iostream>
#include <windows.h>

class LawnDisplay {
public:
    LawnDisplay();
    LawnDisplay(Mower *mower);
    LawnDisplay(Lawn *lawn);

    int*        getMarginOffsets();
    int*        getTitleOffsets();
    int*        getLawnOffsets();
    int*        getStatsOffsets();

    void        setMarginOffsets(int x_offset, int y_offset);
    void        setTitleOffsets(int x_offset, int y_offset);
    void        setLawnOffsets(int x_offset, int y_offset);
    void        setStatsOffsetsint(int x_offset, int y_offset);

    void        draw();
    bool        drawSquare(LawnPos position);
private:
    Mower*      _mower;
    Lawn*       _lawn;
    Position    _cursor_position;
    int         _margin_offsets[2]      = {8, 4};   // offsets from left, top of console default {8, 4}
    int         _title_offsets[2]       = {0, 2};   // offsets from border, border default {0, 2}
    int         _lawn_offsets[2]        = {0, 3};   // offsets from border, title default {0, 3}
    int         _stats_offsets[2]       = {0, 3};   // offsets from border, lawn default {0, 3}
    int         _square_dimension[2]    = {2, 1};   // square size (2 chars) default {2, 1}

    bool        drawMower();
    
    void        moveCursor(Position position);
    void        saveCursorPosition();
    void        restoreCursorPosition();
    void        hideCursor();
    void        showCursor();
};

#endif