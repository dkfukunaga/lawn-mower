
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
        switch (rand() % 4) {
        case 0:
            str = "\",";
            break;
        case 1:
            str = ",\"";
            break;
        case 2:
            str = ";'";
            break;
        case 3:
            str = "';";
            break;
        }
        break;
    case SquareType::mowed:
        str = " .";
        break;
    case SquareType::wall:
        str = "  ";
        break;
    case SquareType::error:
    default:
        str = "??";
        break;
    }

    return str;
}