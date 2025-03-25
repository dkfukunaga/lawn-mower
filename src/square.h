#ifndef SQUARE_H
#define SQUARE_H
#endif

#include <string>

enum class SquareType {
    unmowed,
    mowed,
    wall,
};

struct Coordinates {
    int             x;
    int             y;

    bool            operator==(const Coordinates& other) const;
    bool            operator!=(const Coordinates& other) const;
    Coordinates&    operator=(const Coordinates& other);
};

class Square {
public:
    Square(SquareType type, int x, int y):
        type_(type),
        coordinates_(Coordinates{x, y}) { };
    Square():
        type_(SquareType::unmowed),
        coordinates_(Coordinates{-1,-1}) { };
    
    void            setType(SquareType type);
    void            setCoordinates(int x, int y);
    void            setCoordinates(Coordinates coordinates);

    SquareType      getType() const;
    Coordinates     getCoordinates() const;
    std::string     getString() const;
private:
    SquareType      type_;
    Coordinates     coordinates_;
};