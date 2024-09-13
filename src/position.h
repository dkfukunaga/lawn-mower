

#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int x, int y);
    Position(const Position &that);

    int         getX() const;
    int         getY() const;

    Position    set(int x, int y);
    Position    move(int x, int y);

    bool        operator==(Position &rhs);
    bool        operator!=(Position &rhs);
private:
    int         _x;
    int         _y;
};

#endif