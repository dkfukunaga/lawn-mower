
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "common.h"
#include "lawn.h"
#include "mower.h"
#include <iostream>
#include <windows.h>

class LawnDisplay {
public:
    LawnDisplay(int x_margin, int y_margin);                // defaults to default margins
    LawnDisplay(Mower *mower, int x_margin, int y_margin);  // defaults to default margins
    LawnDisplay(Lawn *lawn, int x_margin, int y_margin);    // defaults to default margins

    int*        getMargins();    
    void        setMargins(int x_margin, int y_margin);

    void        draw();
    bool        drawSquare(LawnPos position);
private:
    static const int _default_margin_offsets[2];    // default border around whole display {8, 4}
    static const int _default_title_offsest[2];     // default title offsets from border, display {0, 2}
    static const int _default_lawn_offsets[2];      // default lawn offsets from border, title {0, }
    static const int _default_stats_offsets[2];     // default stats offsets from border, lawn {0, 3}
    static const int _square_dimensions[2];         // square dimensions in console {2, 1}

    Mower*      _mower;
    Lawn*       _lawn;
    Position    _cursor_position;
    int         _margin_offsets[2];
    int         _title_offsets[2];
    int         _lawn_offsets[2];
    int         _stats_offsets[2];

    bool        drawMower();
    
    void        moveCursor(Position position);
    void        saveCursorPosition();
    void        restoreCursorPosition();
    void        hideCursor();
    void        showCursor();
};

#endif