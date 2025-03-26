#pragma once
#ifndef LAWN_H
#define LAWN_H

#include "square.h"
#include "facing.h"
#include <vector>
#include <string>

class Lawn {
public:
Lawn(int width, int height):
    width_(width),
    height_(height) {
    grid_ = std::vector<Square>();
    grid_.reserve(width * height);
    resetLawn();
};
Lawn() {
    width_ = DEFAULT_WIDTH;
    height_ = DEFAULT_HEIGHT;
    grid_ = std::vector<Square>();
    grid_.reserve(DEFAULT_WIDTH * DEFAULT_HEIGHT);
    resetLawn();
};

    void                    resetLawn();
    bool                    mowSquare(Coordinates position);
    bool                    mowSquare(int x, int y);
    
    void                    setLawn(int width, int height);
    void                    setWidth(int width);
    void                    setHeight(int height);

    int                     getWidth() const;
    int                     getHeight() const;
    Square                  &getSquare(Coordinates position);
    Square                  &getSquare(int x, int y);
    Square                  &getSquare(Coordinates position, Facing::Direction direction);
    Square                  &getSquare(int x, int y, Facing::Direction direction);
    std::string             getString(Coordinates position);
    std::string             getString(int x, int y);
private:
    int                     width_;
    int                     height_;
    std::vector<Square>     grid_;

    const int               DEFAULT_WIDTH = 10;
    const int               DEFAULT_HEIGHT = 10;
    static const Square           ERROR_SQUARE;

    void                    setSquare(SquareType type, Coordinates position);
    void                    setSquare(SquareType type, int x, int y);
    bool                    isValidPosition(Coordinates position);
};


#endif

