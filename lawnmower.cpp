#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

enum class Direction { north, east, south, west };

enum class Square { red, green, visited };

struct Mower {
    Direction facing;
    int x;
    int y;
};

struct Field {
    int height;
    int width;
    Mower mower;
    Square **field = new Square*[height];
};

void initLawn(Field&);
char squareChar(Square&);
char mowerChar(Field&);
void printLawn(Field&);
Square peek(Field&);
int forward(Field&);
void turnLeft(Field&);
void turnRight(Field&);



int main() {

    // randomize the facing of the lawn Mower
    // and set initial position to (1,1), the lower left corner
    srand(time(0));
    Direction initial_facing = static_cast<Direction>(rand() % 4);
    Mower mower = {initial_facing, 1, 1};
    
    // randomize lawn size of 5 - 20 squares, plus a 1 Square border of walls
    srand(time(0));
    const int LAWN_HEIGHT = rand() % 15 + 7;
    const int LAWN_WIDTH = rand() % 15 + 7;

    // const int LAWN_HEIGHT = 7;
    // const int LAWN_WIDTH = 7;

    // declare lawn array
    Field lawn = {LAWN_HEIGHT, LAWN_WIDTH, mower};

    // initialize lawn with walls all along the border and grass in the interior
    initLawn(lawn);

    cout << "\033[?25l";
    
    system("cls");
    cout << "\n" << endl;
    printLawn(lawn);

    /*
     * TODO :
     *   - add mower position and facing below field
     *   - implement delay for forward function
     *   - implement lawn mower algorithm
     *   - implement keyboard controls and menu select
     */
    


    forward(lawn);
    forward(lawn);
    forward(lawn);
    forward(lawn);
    forward(lawn);
    forward(lawn);

    // cout << endl << endl << endl;
    // system("CLS");
    // printLawn(lawn);
    
    // cout << "\033[2;3H" << "@";
    // int n = LAWN_HEIGHT - 1;
    // cout << "\033[" << n << "E";

    // move cursor to bottom
    cout << "\033[" << LAWN_HEIGHT + 5 << ";1H";
    cout << "\033[?25h";

    return 0;
}

void initLawn(Field &lawn) {

    for (int i = 0; i < lawn.height; i++) {
        // declare array for each row
        lawn.field[i] = new Square[lawn.width];
        // set west wall as red
        lawn.field[i][0] = Square::red;
        for (int j = 1; j < lawn.width - 1; j++) {
            if ((i == 0) || (i == (lawn.height - 1))) {
                // set Direction::north:and south walls as red
                lawn.field[i][j] = Square::red;
            } else {
                // grassy interior
                lawn.field[i][j] = Square::green;
            }
        }
        // set east wall as red
        lawn.field[i][lawn.width - 1] = Square::red;
    }

    // set initial Mower position to visited
    lawn.field[1][1] = Square::visited;

}

void printLawn(Field &lawn) {

    char sq;

    for (int i =  lawn.height - 1; i >= 0; i--) {

        cout << "    ";

        for (int j = 0; j < lawn.width; j++) {
            Square current_square = lawn.field[i][j];
            if ((i == lawn.mower.y) && (j == lawn.mower.x)) {
                sq = mowerChar(lawn);
            } else {
                sq = squareChar(current_square);
            }
            
            cout << sq << " ";
        }
        cout << endl;
    }
    cout << endl;

    
    // set initial cursor position to lower left
    cout << "\033[3A" << "\033[6C";

}

char squareChar(Square &square) {

    char ch;

    switch (square) {
        case Square::red:
            ch = '#';
            break;
        case Square::green:
            ch = '"';
            break;
        case Square::visited:
            ch = '.';
            break;
        default: // should never happen, but just in case
            ch = '?';
            break;
        }

    return ch;
}

char mowerChar(Field &lawn) {

    char ch;

    switch (lawn.mower.facing) {
        case Direction::north:
            ch = '^';
            break;
        case Direction::east:
            ch = '>';
            break;
        case Direction::south:
            ch = 'v';
            break;
        case Direction::west:
            ch = '<';
            break;
        default: // should never happen, but just in case
            ch = '@';
            break;
    }

    return ch;
}

Square peek(Field &lawn) {

    Square next;

    switch (lawn.mower.facing) {
        case Direction::north:
            next = lawn.field[lawn.mower.y + 1][lawn.mower.x];
            break;
        case Direction::east:
            next = lawn.field[lawn.mower.y][lawn.mower.x + 1];
            break;
        case Direction::south:
            next = lawn.field[lawn.mower.y - 1][lawn.mower.x];
            break;
        case Direction::west:
            next = lawn.field[lawn.mower.y][lawn.mower.x - 1];
            break;
    }

    return next;
}

// return 1 if successful,
// return 0 if unsuccessful
int forward(Field &lawn) {

    if (peek(lawn) == Square::red) {
        // cannot move onto wall Square
        return 0;
    }

    Sleep(250);

    // print lawn square on old mower position
    cout << squareChar(lawn.field[lawn.mower.y][lawn.mower.x]) << "\b";

    switch (lawn.mower.facing) {
        case Direction::north:
            lawn.mower.y++;
            cout << "\033[1A";
            break;
        case Direction::east:
            lawn.mower.x++;
            cout << "\033[2C";
            break;
        case Direction::south:
            lawn.mower.y--;
            cout << "\033[1B";
            break;
        case Direction::west:
            lawn.mower.x--;
            cout << "\033[2D";
            break;
        default: // should never happen, but just in case
            return 0;
    }

    // mark new Square as visited
    lawn.field[lawn.mower.y][lawn.mower.x] = Square::visited;

    // print new mower position
    cout << mowerChar(lawn) << "\b";

    // return 1 for success
    return 1;
}

void turnLeft(Field &lawn) {

    int temp = static_cast<int>(lawn.mower.facing);
    temp = (temp + 1) % 4;

    lawn.mower.facing = static_cast<Direction>(temp);
}
void turnRight(Field &lawn) {

    int temp = static_cast<int>(lawn.mower.facing);
    temp = (temp - 1) % 4;

    lawn.mower.facing = static_cast<Direction>(temp);
}