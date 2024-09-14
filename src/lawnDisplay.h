
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "lawn.h"
#include "mower.h"
#include "position.h"
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
    void        setStatsOffsets(int x_offset, int y_offset);

    void        drawScreen();
    bool        refreshLawn();
    void        moveToBottom();

    SquareType  mowerPeek();
    void        mowerForward();
    void        mowerTurnLeft();
    void        mowerTurnRight();
private:
    std::string _title = "Lawn Mower Simulation";

    Mower*      _mower;
    int         _margin_offsets[2]   = {8, 2};  // offsets relative to left, top of console default {8, 4}
    int         _title_offsets[2]    = {4, 0};  // offsets relative to margin, border default {0, 0}
    int         _lawn_offsets[2]     = {0, 2};  // offsets relative to margin, title default {0, 3}
    int         _stats_offsets[2]    = {4, 2};  // offsets relative to margin, lawn default {0, 3}
    int         _square_dimension[2] = {2, 1};  // square size (2 chars) default {2, 1}
    int         _title_height        = 1;       // currently single line title
    int         _stats_height        = 0;       // stats display not yet implemented
    Position    _bottom_pos;

    void        drawSquare(LawnPos position);
    void        drawStats();
    void        updateMowerPosition();
    void        updateMowerPeeks();
    void        updateMowerTurns();
    void        updateMowerSteps();
    void        updateMowerTotal();
    
    void        moveCursor(Position position);
    void        moveCursor(int x, int y);
    void        moveCursorToLawnPos(LawnPos position);
    void        hideCursor();
    void        showCursor();

    // LawnPos     convertToLawnPos(Position position);
};

#endif