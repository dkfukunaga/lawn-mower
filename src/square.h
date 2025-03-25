#ifndef SQUARE_H
#define SQUARE_H

#include "coordinates.h"
#include <string>

enum class SquareType {
    unmowed,
    mowed,
    wall,
};

class Square {
public:
Square(SquareType type, int x, int y):
    type_(type),
    coordinates_(Coordinates{x, y}) { };
    Square(SquareType type, Coordinates coordinates):
        type_(type),
        coordinates_(coordinates) { };
    Square(SquareType type):
        type_(type),
        coordinates_(Coordinates{-1, -1}) { };
    Square():
        type_(SquareType::unmowed),
        coordinates_(Coordinates{-1, -1}) { };
    
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


#endif