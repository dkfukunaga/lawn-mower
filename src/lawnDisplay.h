
#ifndef LAWN_DISPLAY_H
#define LAWN_DISPLAY_H

#include "common.h"
#include "lawn.h"
#include "mower.h"
#include <string>

class LawnDisplay {
public:
    LawnDisplay();
    LawnDisplay(Mower mower);
    LawnDisplay(Mower mower, Lawn _lawn);

    void        fullRefresh();
    bool        refreshSquare(Position position);
private:
    Mower       _mower;
    Lawn*       _lawn;
    Position    _cursor_position;

    bool        drawSquare(Position position);
    bool        drawMower();

    std::string squareString(Square square);

    void        hideCursor();
    void        showCursor();
    void        moveCursor(Position position);
    void        saveCursorPosition();
    void        restoreCursorPosition();
};

#endif