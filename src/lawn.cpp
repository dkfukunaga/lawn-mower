

#include "lawn.h"
#include "square.h"
#include "coordinates.h"



void                    Lawn::resetLawn() {
    for (int row  = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            if (row == 0 || row == (height_ - 1) ||
                col == 0 || col == (width_ - 1)) {
                setSquare(SquareType::wall, Coordinates{col, row});
            } else {
                setSquare(SquareType::unmowed, Coordinates{col, row});
            }
        }
    }
}

void                    Lawn::setLawn(int width, int height) {
    width_ = width;
    height_ = height;
    grid_.resize(width_ * height_);
    initLawn();
}

bool                    Lawn::mowSquare(Coordinates location) {
    if (getSquare(location).getType() == SquareType::unmowed) {
        setSquare(SquareType::mowed, location);
        return true;
    }
    return false;
}

bool                    Lawn::mowSquare(int x, int y) {
    return mowSquare(Coordinates{x, y});
}


int                     Lawn::getWidth() const { return width_; }
int                     Lawn::getHeight() const { return height_; }
Square                  Lawn::getSquare(Coordinates location) const {
    int index = location.y * width_ + location.x;
    return grid_[index];
}

Square                  Lawn::getSquare(int x, int y) const {
    return getSquare(Coordinates{x, y});
}

std::string             Lawn::getString(Coordinates location) const {
    return getSquare(location).getString();
}

std::string             Lawn::getString(int x, int y) const {
    return getString(Coordinates{x, y});
}




void                    Lawn::initLawn() {
    for (int row  = 0; row < height_; ++row) {
        for (int col = 0; col < width_; ++col) {
            if (row == 0 || row == (height_ - 1) ||
                col == 0 || col == (width_ - 1)) {
                grid_[row * width_ + col] = Square(SquareType::wall, Coordinates{col, row});
            } else {
                grid_[row * width_ + col] = Square(SquareType::unmowed, Coordinates{col, row});
            }
        }
    }
}

void                    Lawn::setSquare(SquareType type, Coordinates location) {
    getSquare(location).setType(type);
}

void                    Lawn::setSquare(SquareType type, int x, int y) {
    setSquare(type, Coordinates{x, y});
}


