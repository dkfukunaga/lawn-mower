
#ifndef COORDINATES_H
#define COORDINATES_H



struct Coordinates {
    int             x;
    int             y;

    bool            operator==(const Coordinates& other) const;
    bool            operator!=(const Coordinates& other) const;
    Coordinates&    operator=(const Coordinates& other);
};




#endif