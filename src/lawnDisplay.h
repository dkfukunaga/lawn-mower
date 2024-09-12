
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "common.h"
#include "lawn.h"
#include "mower.h"
#include <iostream>
#include <windows.h>

class LawnDisplay {
public:
    LawnDisplay(int margin_size);
    LawnDisplay(Mower *mower, int margin_size);
    LawnDisplay(Lawn *lawn, int margin_size);

    int         getMarginSize();
    void        setMarginSize(int margin_size);

    void        draw();
    bool        drawSquare(LawnPos position);
private:
    static const int _default_side_margin;      // border around whole display
    static const int _default_title_x_offset;   // title x offset from border
    static const int _default_title_y_offset;   // title y offset from border
    static const int _default_lawn_x_offset;    // lawn x offset from border
    static const int _default_lawn_y_offset;    // lawn y offset from title
    static const int _default_stats_x_offset;   // stats x offset from border
    static const int _default_stats_y_offset;   // stats y offset from lawn
    static const int _square_dimensions[2];

    Mower*      _mower;
    Lawn*       _lawn;
    Position    _cursor_position;
    int         _margin_size    = _default_side_margin;
    int         _title_x_offset = _default_title_x_offset;
    int         _title_y_offset = _default_title_y_offset;
    int         _lawn_x_offset  = _default_lawn_x_offset;
    int         _lawn_y_offset  = _default_lawn_y_offset;
    int         _stats_x_offset = _default_stats_x_offset;
    int         _stats_y_offset = _default_stats_y_offset;

    bool        drawMower();
    
    void        moveCursor(Position position);
    void        saveCursorPosition();
    void        restoreCursorPosition();
    void        hideCursor();
    void        showCursor();
};

#endif