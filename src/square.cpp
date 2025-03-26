
#include "square.h"
#include <string>
#include <random>


void            Square::setType(SquareType type) { type_ = type; }
void            Square::setCoordinates(int x, int y) { coordinates_ = Coordinates{x, y}; }
void            Square::setCoordinates(Coordinates coordinates) {  coordinates_ = coordinates; }

SquareType      Square::getType() { return type_; }
Coordinates     Square::getCoordinates() { return coordinates_; }


std::string     Square::getString() {
    std::string str;

    switch (type_) {
    case SquareType::unmowed:
        switch (rand() % 2) {
        case 0:
            str = "\",";
        default:
            str = ",\"";
        }
        break;
    case SquareType::mowed:
        str = " .";
        break;
    case SquareType::wall:
        str = "  ";
        break;
    default:
        str = "??";
        break;
    }

    return str;
}