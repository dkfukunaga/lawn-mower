
#include "tester.h"
#include "..\src\square.h"

TEST_CASE("Test Square constructors, getters, setters") {
    // create default square
    Square default_square;

    // should default to error square
    CHECK(default_square.getType() == SquareType::error);

    // use full constructor to create wall square
    Square test_square(SquareType::wall);

    // test wall square
    CHECK(test_square.getType() == SquareType::wall);

    // use setter to test unmowed and mowed squares
    test_square.setType(SquareType::unmowed);
    CHECK(test_square.getType() == SquareType::unmowed);
    test_square.setType(SquareType::mowed);
    CHECK(test_square.getType() == SquareType::mowed);
}

TEST_CASE("Test Square strings") {
    // set random seed
    srand(time(NULL));

    // create error, wall, and mowed squares and test
    Square error_square(SquareType::error);
    Square wall_square(SquareType::wall);
    Square mowed_square(SquareType::mowed);

    CHECK(error_square.getString() == "??");
    CHECK(wall_square.getString() == "##");
    CHECK(mowed_square.getString() == " .");

    std::cout << "Square strings:\n";
    std::cout << "  " << "error:   [" << error_square.getString() << "]" << std::endl;
    std::cout << "  " << "wall:    [" << wall_square.getString() << "]" << std::endl;
    std::cout << "  " << "mowed:   [" << mowed_square.getString() << "]" << std::endl;

    // // create array of unmowed squares to make sure both
    // // randomized strings are tested
    // int unmowed_count = 15;
    // Square unmowed_squares[unmowed_count];

    // // create unmowed squares
    // // print for visual confirmation both variants were tested
    // std::cout << "unmowed square strings:\n";
    // for (int i = 0; i < unmowed_count; ++i) {
    //     unmowed_squares[i].setType(SquareType::unmowed);
    //     printf("  %2d: \"%s\"\n", i, unmowed_squares[i].getString().c_str());
    //     // std::cout << "  " << i << ": \"" << unmowed_squares[i].getString() << "\"\n";
    // }
    // std::cout << std::endl;

    
    char variants[6] = {0b00000001,     // variant 0
                        0b00000010,     // variant 1
                        0b00000100,     // variant 2
                        0b00001000,     // variant 3
                        0b00010000,     // variant 4
                        0b00100000};    // variant 5
    char variant_mask = 0b00111111;
    char variant_flags = 0b00000000;
    
    std::cout << "  " << "unmowed: ";
    
    while ((variant_flags & variant_mask) != variant_mask) {
        Square unmowed_square(SquareType::unmowed);
        int variant = unmowed_square.getVariant();
        switch (variant) {
            case 0:
                if ((variant_flags & variants[variant]) == 0) {
                    variant_flags |= variants[variant];
                    CHECK(unmowed_square.getString() == "\",");
                    std::cout << "[" << unmowed_square.getString() << "]";
                }
                break;
            case 1:
                if ((variant_flags & variants[variant]) == 0) {
                    variant_flags |= variants[variant];
                    CHECK(unmowed_square.getString() == ",\"");
                    std::cout << "[" << unmowed_square.getString() << "]";
                }
                break;
            case 2:
                if ((variant_flags & variants[variant]) == 0) {
                    variant_flags |= variants[variant];
                    CHECK(unmowed_square.getString() == ";'");
                    std::cout << "[" << unmowed_square.getString() << "]";
                }
                break;
            case 3:
                if ((variant_flags & variants[variant]) == 0) {
                    variant_flags |= variants[variant];
                    CHECK(unmowed_square.getString() == "';");
                    std::cout << "[" << unmowed_square.getString() << "]";
                }
                break;
            case 4:
                if ((variant_flags & variants[variant]) == 0) {
                    variant_flags |= variants[variant];
                    CHECK(unmowed_square.getString() == ";\"");
                    std::cout << "[" << unmowed_square.getString() << "]";
                }
                break;
            case 5:
                if ((variant_flags & variants[variant]) == 0) {
                    variant_flags |= variants[variant];
                    CHECK(unmowed_square.getString() == "\";");
                    std::cout << "[" << unmowed_square.getString() << "]";
                }
                break;
        }
    }
    std::cout << std::endl;
}