
#ifndef LAWN_H
#define LAWN_H

#include "square.h"
#include "direction.h"
#include <vector>
#include <string>

class Lawn {
public:
    Lawn(int width = 10, int height = 10):
        width_(width),
        height_(height),
        grid_(width * height) {
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
    Square                  getSquare(Coordinates position) const;
    Square                  getSquare(int x, int y) const;
    Square                  getSquare(Coordinates position, Direction direction) const;
    Square                  getSquare(int x, int y, Direction direction) const;
    std::string             getString(Coordinates position) const;
    std::string             getString(int x, int y) const;
private:
    int                     width_;
    int                     height_;
    std::vector<Square>     grid_;

    void                    setSquare(SquareType type, Coordinates position);
    void                    setSquare(SquareType type, int x, int y);
    bool                    isValidPosition(Coordinates position) const;
};


#endif

