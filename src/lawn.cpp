

#include "lawn.h"
#include "square.h"
#include "coordinates.h"


const Square Lawn::ERROR_SQUARE = Square(SquareType::error);

void                    Lawn::resetLawn() {
    for (int row  = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            if (row == 0 || row == (height_ - 1) ||
                col == 0 || col == (width_ - 1)) {
                grid_.push_back(Square(SquareType::wall, Coordinates{col, row}));
                // setSquare(SquareType::wall, Coordinates{col, row});
            } else {
                grid_.push_back(Square(SquareType::unmowed, Coordinates{col, row}));
                // setSquare(SquareType::unmowed, Coordinates{col, row});
            }
        }
    }
}

bool                    Lawn::mowSquare(Coordinates location) {
    if (isValidPosition(location) &&
        getSquare(location).getType() == SquareType::unmowed) {
        setSquare(SquareType::mowed, location);
        return true;
    }
    return false;
}

bool                    Lawn::mowSquare(int x, int y) {
    return mowSquare(Coordinates{x, y});
}

void                    Lawn::setLawn(int width, int height) {
    width_ = width;
    height_ = height;
    grid_.resize(width_ * height_);
    resetLawn();
}

void                    Lawn::setWidth(int width) {
    width_ = width;
    grid_.resize(width_ * height_);
    resetLawn();
}

void                    Lawn::setHeight(int height) {
    height_ = height;
    grid_.resize(width_ * height_);
    resetLawn();
}


int                     Lawn::getWidth() const { return width_; }
int                     Lawn::getHeight() const { return height_; }
Square                  &Lawn::getSquare(Coordinates location) {
    if (isValidPosition(location)) {
        int index = location.y * width_ + location.x;
        return grid_.at(index);
    }
    return *const_cast<Square*>(&ERROR_SQUARE);
}

Square                  &Lawn::getSquare(int x, int y) {
    return getSquare(Coordinates{x, y});
}

Square                  &Lawn::getSquare(Coordinates position, Facing::Direction direction) {
    Coordinates pos = position.getNext(direction);
    if (isValidPosition(pos)) {
        return getSquare(pos);
    }
    return *const_cast<Square*>(&ERROR_SQUARE);
}

Square                  &Lawn::getSquare(int x, int y, Facing::Direction direction) {
    return getSquare(Coordinates{x, y}, direction);
}

std::string             Lawn::getString(Coordinates location) {
    return getSquare(location).getString();
}

std::string             Lawn::getString(int x, int y) {
    return getString(Coordinates{x, y});
}


void                    Lawn::setSquare(SquareType type, Coordinates location) {
    getSquare(location).setType(type);
}

void                    Lawn::setSquare(SquareType type, int x, int y) {
    setSquare(type, Coordinates{x, y});
}

bool                    Lawn::isValidPosition(Coordinates position) {
    return (position.x >= 0 && position.x < width_) &&
           (position.y >= 0 && position.y < height_);
    // return true;
}
