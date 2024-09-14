
#include "square.h"

/***** STATIC CONSTANTS *****/

const std::string Square::_error_string         = "??";
const std::string Square::_wall_string[3]       = {"##", "# ", " #"};
const std::string Square::_unmowed_string[6]    = {"\",", ",\"",
                                                   ";'", "';",
                                                   ";\"", "\";"};
const std::string Square::_mowed_string         = " .";

/***** CONSTRUCTORS *****/

// default constructor
// defaults to error type
// rolls random variant
Square::Square():
    _type(SquareType::error) {
    rollVariant();
};

// type constructor
// rolls random variant
Square::Square(SquareType type):
    _type(type) {
    rollVariant();
};

// full constructor
// rolls random variant
Square::Square(SquareType type, int variant):
    _type(type) {
    setVariant(variant);
}
    
/***** GETTERS/ACCESSORS *****/

// returns SquareType
SquareType Square::getType() const { return _type; }

// returns variant type for squres with randomized strings
int Square::getVariant() const { return _variant; }

// returns 2 char ascii string representation of square type
// error:   [??]
// wall:    [##][# ][ #]
// unmowed: [",][,"][;'][';][;"][";]
// mowed:   [ .]
std::string Square::getString() const {
    switch (_type) {
        case SquareType::error:
            return _error_string;
            break;
        case SquareType::wall:
            return _wall_string[_variant];
            break;
        case SquareType::unmowed:
            return _unmowed_string[_variant];
            break;
        case SquareType::mowed:
            return _mowed_string;
            break;
    }

    return _error_string;
}

/***** SETTERS/MUTATORS *****/

// sets SquareType with no error checking
void Square::setType(SquareType type) {
    _type = type;
    rollVariant();
}

// sets variant
// invalid inputs default to variant 0
void Square::setVariant(int variant) {
    switch (static_cast<int>(_type)) {
        case 0:                         // error
            _variant = 0;
            break;
        case 1:                         // wall
            _variant = (variant >= 0 && variant <= 3 ? variant : 0);
            break;
        case 2:                         // unmowed
            _variant = (variant >= 0 && variant <= 6 ? variant : 0);
            break;
        case 3:                         // mowed
            _variant = 0;
            break;
        default:
            _variant = 0;
            break;
    }
}


/***** PRIVATE HELPER FUNCTIONS *****/

// rolls variant for unmowed
// walls default to variant 0
// types without variants default to variant 0
void Square::rollVariant() {
    switch (static_cast<int>(_type)) {
        case 0:                         // error
            _variant = 0;
            break;
        case 1:                         // wall
            _variant = 0;
            break;
        case 2:                         // unmowed
            _variant = rand() % 6;
            break;
        case 3:                         // mowed
            _variant = 0;
            break;
        default:
            _variant = 0;
            break;
    }
    
}