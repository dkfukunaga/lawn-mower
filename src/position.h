

#ifndef POSITION_H
#define POSITION_H

// cardinal direction on lawn
enum class Direction {
    north,
    west,
    south,
    east
};

class Position {
public:
    Position();
    Position(int x, int y);
    Position(const Position &that);

    int         getX() const;
    int         getY() const;

    Position    north() const;
    Position    west() const;
    Position    south() const;
    Position    east() const;
    
    Position    set(int x, int y);
    Position    set(Position position);
    Position    move(int x, int y);
    Position    move(Direction direction);

    Position&   operator=(const Position &rhs);
    bool        operator==(const Position &rhs);
    bool        operator!=(const Position &rhs);
private:
    int         _x;
    int         _y;
};

typedef Position LawnPos;

#endif