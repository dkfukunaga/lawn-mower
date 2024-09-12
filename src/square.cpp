
#include "square.h"

/***** STATIC CONSTANTS *****/

const std::string Square::_error_string = "??";
const std::string Square::_wall_string = "##";  // will be blank when colorization implemented
const std::string Square::_unmowed_string[2] = {"\",", ",\""};  // can be randomized
const std::string Square::_mowed_string = ". ";

/***** CONSTRUCTORS *****/

// default constructor
// defaults to error type
Square::Square():
    _type(SquareType::error) { };

// full constructor
Square::Square(SquareType type):
    _type(type) { };
    
/***** GETTERS/ACCESSORS *****/

// returns SquareType
SquareType Square::getType() { return _type; }

// returns 2 char ascii string representation of square type
// error:   "??"
// wall:    "  "
// unmowed: "\"," or ",\""
// mowed:   " ."
std::string Square::getString() {
    switch (_type) {
        case SquareType::error:
            return _error_string;
            break;
        case SquareType::wall:
            return _wall_string;
            break;
        case SquareType::unmowed:
            srand(time(NULL));
            int randomizer = rand() % 2;
            return _unmowed_string[randomizer];
            break;
        case SquareType::mowed:
            return _mowed_string;
            break;
    }

    return "??";
}

/***** SETTERS/MUTATORS *****/

// sets SquareType with no error checking
void Square::setType(SquareType type) { _type = type; }