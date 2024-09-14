
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

    // create array of unmowed squares to make sure both
    // randomized strings are tested
    int unmowed_count = 15;
    Square unmowed_squares[unmowed_count];

    // create unmowed squares
    // print for visual confirmation both variants were tested
    std::cout << "unmowed square strings:\n";
    for (int i = 0; i < unmowed_count; ++i) {
        unmowed_squares[i].setType(SquareType::unmowed);
        printf("  %2d: \"%s\"\n", i, unmowed_squares[i].getString().c_str());
        // std::cout << "  " << i << ": \"" << unmowed_squares[i].getString() << "\"\n";
    }
    std::cout << std::endl;

    // test unmowed square strings
    for (int i = 0; i < unmowed_count; ++i) {
        switch (unmowed_squares[i].getVariant()) {
            case 0:
                CHECK(unmowed_squares[i].getString() == "\",");
                break;
            case 1:
                CHECK(unmowed_squares[i].getString() == ",\"");
                break;
            case 2:
                CHECK(unmowed_squares[i].getString() == ";'");
                break;
            case 3:
                CHECK(unmowed_squares[i].getString() == "';");
                break;
            case 4:
                CHECK(unmowed_squares[i].getString() == ";\"");
                break;
            case 5:
                CHECK(unmowed_squares[i].getString() == "\";");
                break;
        }
    }
}