
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
    bool        drawSquare(Position position);
private:
    Mower*      _mower;
    Lawn*       _lawn;
    Position    _cursor_position;
    int         _margin_size;
    std::string _margin;
    
    static const int _default_margin_size;

    bool        drawSquare(Position position);
    bool        drawMower();

    void        moveCursor(Position position);
    void        saveCursorPosition();
    void        restoreCursorPosition();
    void        hideCursor();
    void        showCursor();
};

#endif