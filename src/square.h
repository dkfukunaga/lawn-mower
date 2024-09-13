
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

    SquareType      getType() const;
    int             getVariant() const;
    std::string     getString() const;

    void            setType(SquareType type);
private:
    SquareType      _type;
    int             _variant;   // only used by unmowed squares

    static const std::string _error_string;         // "??"
    static const std::string _wall_string;          // "##"
    static const std::string _unmowed_string[2];    // ""," or ",""
    static const std::string _mowed_string;         // " ."
};

#endif