
#ifndef LAWN_H
#define LAWN_H

#include "square.h"
#include <vector>
#include <string>

class Lawn {
public:
    Lawn(int width, int height):
        width_(width),
        height_(height),
        grid_(width * height) {
        initLawn();
    };
    Lawn() { Lawn(10, 10); };

    void                    resetLawn();
    void                    setLawn(int width, int height);
    bool                    mowSquare(Coordinates location);
    bool                    mowSquare(int x, int y);

    int                     getWidth() const;
    int                     getHeight() const;
    Square                  getSquare(Coordinates location) const;
    Square                  getSquare(int x, int y) const;
    std::string             getString(Coordinates location) const;
    std::string             getString(int x, int y) const;
private:
    int                     width_;
    int                     height_;
    std::vector<Square>     grid_;

    void                    initLawn();
    void                    setSquare(SquareType type, Coordinates location);
    void                    setSquare(SquareType type, int x, int y);
};


#endif

