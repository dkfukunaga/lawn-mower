#ifndef LAWN_H
#define LAWN_H


enum class Square {
    wall,       // red
    unmowed,    // green
    mowed       // green
};


class Lawn {
public:
    // constructor
    Lawn(int width, int height):
        _width(width),
        _height(height) {
        _field = new Square[width*height];
        initField();
    };
    // destructor
    ~Lawn() { delete _field; };
    // public functions
    Square  getSquare(int x, int y);
    bool    mowSquare(int x, int y);
private:
    // private data
    int     _width;
    int     _height;
    Square* _field;

    // helper functions
    void    initField();
};

#endif