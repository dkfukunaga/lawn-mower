
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

    Square square;

    std::cout << "Square strings:\n";

    // test error square
    square.setType(SquareType::error);
    CHECK(square.getString() == "??");
    std::cout << "  " << "error:   [" << square.getString() << "]" << std::endl;

    // test wall square
    square.setType(SquareType::wall);
    // variant 0
    square.setVariant(0);
    CHECK(square.getString() == "##");
    std::cout << "  " << "wall:    [" << square.getString() << "]";
    // variant 1
    square.setVariant(1);
    CHECK(square.getString() == "# ");
    std::cout << "[" << square.getString() << "]";
    // variant 2
    square.setVariant(2);
    CHECK(square.getString() == " #");
    std::cout << "[" << square.getString() << "]" << std::endl;

    // test unmowed square
    square.setType(SquareType::unmowed);
    std::cout << "  " << "unmowed: ";
    // variant 0
    square.setVariant(0);
    CHECK(square.getString() == "\",");
    std::cout << "[" << square.getString() << "]";
    // variant 1
    square.setVariant(1);
    CHECK(square.getString() == ",\"");
    std::cout << "[" << square.getString() << "]";
    // variant 2
    square.setVariant(2);
    CHECK(square.getString() == ";'");
    std::cout << "[" << square.getString() << "]";
    // variant 3
    square.setVariant(3);
    CHECK(square.getString() == "';");
    std::cout << "[" << square.getString() << "]";
    // variant 4
    square.setVariant(4);
    CHECK(square.getString() == ";\"");
    std::cout << "[" << square.getString() << "]";
    // variant 5
    square.setVariant(5);
    CHECK(square.getString() == "\";");
    std::cout << "[" << square.getString() << "]" << std::endl;

    // test mowed square
    square.setType(SquareType::mowed);
    CHECK(square.getString() == " .");
    std::cout << "  " << "mowed:   [" << square.getString() << "]" << std::endl;

    std::cout << std::endl;
}