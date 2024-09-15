
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "lawn.h"
#include "mower.h"
#include "position.h"
#include "direction.h"
#include <windows.h>

class LawnDisplay {
public:
    LawnDisplay();
    LawnDisplay(Mower *mower);
    LawnDisplay(Lawn *lawn);
    ~LawnDisplay();

    int*        getMarginOffsets();
    int*        getTitleOffsets();
    int*        getLawnOffsets();
    int*        getStatsOffsets();

    Direction   getMowerFacing();
    LawnPos     getMowerLawnPos();
    Square      getMowerSquare();
    int         getMowerPeeks();
    int         getMowerTurns();
    int         getMowerSteps();
    int         getMowerTotal();
    int         getLawnHeight();
    int         getLawnWidth();
    Square      getLawnSquare(LawnPos lawn_pos);

    void        setMarginOffsets(int x_offset, int y_offset);
    void        setTitleOffsets(int x_offset, int y_offset);
    void        setLawnOffsets(int x_offset, int y_offset);
    void        setStatsOffsets(int x_offset, int y_offset);

    void        drawScreen();
    bool        refreshLawn();
    void        moveToBottom();

    SquareType  mowerPeek();
    bool        mowerForward();
    void        mowerTurnLeft();
    void        mowerTurnRight();
private:
    static const std::string _title[3];
    static const std::string _stats_layout[7];

    Mower*      _mower;
    Lawn*       _lawn;

    int         _margin_offsets[2]   = {8, 2};  // offsets relative to left, top of console default {8, 4}
    int         _title_offsets[2]    = {0, 0};  // offsets relative to margin, border default {0, 0}
    int         _lawn_offsets[2]     = {2, 1};  // offsets relative to margin, title default {0, 3}
    int         _stats_offsets[2]    = {0, 1};  // offsets relative to margin, lawn default {0, 3}
    int         _square_dimension[2] = {2, 1};  // square size (2 chars) default {2, 1}

    int         _title_height        = 3;       // currently single line title
    int         _stats_height        = 7;       // ASCII table

    Position    _peeks_pos;
    Position    _turns_pos;
    Position    _steps_pos;
    Position    _total_pos;
    Position    _mower_dir_pos;
    Position    _mower_x_pos;
    Position    _mower_y_pos;
    Position    _bottom_pos;

    void        drawSquare(LawnPos position);
    void        drawTitle(int margin);
    void        drawLawn(int margin);
    void        drawStats(int margin);
    void        updateMowerPeeks();
    void        updateMowerTurns();
    void        updateMowerSteps();
    void        updateMowerTotal();
    void        updateMowerPosition();
    
    void        moveCursor(Position position);
    void        moveCursor(int x, int y);
    void        moveCursorToLawnPos(LawnPos position);
    void        hideCursor();
    void        showCursor();

    void        init();

    // LawnPos     convertToLawnPos(Position position);
};

#endif