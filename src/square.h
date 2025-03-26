#ifndef SQUARE_H
#define SQUARE_H

#include "coordinates.h"
#include <string>

enum class SquareType {
    unmowed,
    mowed,
    wall,
    error,
};

class Square {
public:
    Square(SquareType type = SquareType::unmowed, Coordinates coordinates = Coordinates{-1, -1}):
        type_(type),
        coordinates_(coordinates) { };
    Square(SquareType type, int x, int y) {
        Square(type, Coordinates{x, y});
    };

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