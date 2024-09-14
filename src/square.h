
#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <random>
#include <ctime>

// square types on lawn
enum class SquareType {
    error,      // invalid square
    wall,       // red
    unmowed,    // green
    mowed       // green
};

class Square {
public:
    Square();
    Square(SquareType type);
    Square(SquareType type, int variant);

    SquareType      getType() const;
    int             getVariant() const;
    std::string     getString() const;

    void            setType(SquareType type);
    void            setVariant(int variant);
private:
    SquareType      _type;
    int             _variant;   // only used by unmowed squares

    void            rollVariant();

    static const std::string _error_string;         // "??"
    static const std::string _wall_string[3];       // "# " " #" "##"
    static const std::string _unmowed_string[6];    // ", ," ;' '; ;" ";
    static const std::string _mowed_string;         // " ."
};

#endif