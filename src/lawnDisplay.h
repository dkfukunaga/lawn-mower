
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
    LawnPos     getLawnPosition() const;

    void        setMarginOffsets(int x_offset, int y_offset);
    void        setTitleOffsets(int x_offset, int y_offset);
    void        setLawnOffsets(int x_offset, int y_offset);
    void        setStatsOffsets(int x_offset, int y_offset);

    void        draw();
    void        moveMower(Direction direction);
private:
    static const std::string _title;

    Mower*      _mower;
    Position    _cursor_position;               // absolute position of cursor
    int         _margin_offsets[2]   = {8, 4};  // offsets relative to left, top of console default {8, 4}
    int         _title_offsets[2]    = {0, 0};  // offsets relative to margin, border default {0, 0}
    int         _lawn_offsets[2]     = {0, 3};  // offsets relative to margin, title default {0, 3}
    int         _stats_offsets[2]    = {0, 3};  // offsets relative to margin, lawn default {0, 3}
    int         _square_dimension[2] = {2, 1};  // square size (2 chars) default {2, 1}

    void        drawSquare(LawnPos position);
    void        drawStats();
    void        updateMowerPosition();
    void        updateMowerPeeks();
    void        updateMowerTurns();
    void        updateMowerSteps();
    void        updateMowerTotal();
    
    void        moveCursor(Position position);
    void        saveCursorPosition();
    void        restoreCursorPosition();
    void        hideCursor();
    void        showCursor();
    
    Position    convertLawnPosition(LawnPos lawn_position) const;
};

#endif