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
string squareString(Square&);
string mowerString(Field&);
void printLawn(Field&);
void moveTo(Field&, int, int);
void savePos();
void restorePos();
void updateMowerPos(Field&);
string getFacing(Field&);
string getPos(Field&);
Square peek(Field&);
void forward(Field&);
void turnLeft(Field&);
void turnRight(Field&);
void hideCursor();
void showCursor();


int main() {

    // randomize the facing of the lawn Mower
    // and set initial position to (1,1), the lower left corner
    srand(time(0));
    Direction initial_facing = static_cast<Direction>(rand() % 4);
    Mower mower = {initial_facing, 1, 1};
    
    // randomize lawn height and width of 5 - 20 Squares, plus a 1 Square border of walls
    srand(time(0));
    const int LAWN_HEIGHT = rand() % 15 + 7;
    const int LAWN_WIDTH = rand() % 15 + 7;

    // declare lawn
    Field lawn = {LAWN_HEIGHT, LAWN_WIDTH, mower};

    // initialize lawn with walls all along the border and grass in the interior
    initLawn(lawn);

    // make cursor invisible
    // cout << "\033[?25l";
    hideCursor();
    
    // clear screen and add 2 lines of top padding
    system("cls");
    cout << "\n" << endl;
    printLawn(lawn);

    /*
     * TODO :
     *   - implement lawn mower algorithm
     *   - implement keyboard controls and menu select
     */
    

    forward(lawn);
    forward(lawn);
    turnLeft(lawn);
    forward(lawn);
    forward(lawn);
    turnLeft(lawn);
    forward(lawn);
    forward(lawn);
    turnLeft(lawn);
    forward(lawn);
    forward(lawn);
    turnLeft(lawn);
    forward(lawn);
    forward(lawn);
    turnLeft(lawn);
    forward(lawn);
    forward(lawn);

    forward(lawn);
    forward(lawn);
    turnRight(lawn);
    forward(lawn);
    forward(lawn);
    turnRight(lawn);
    forward(lawn);
    forward(lawn);
    turnRight(lawn);
    forward(lawn);
    forward(lawn);
    turnRight(lawn);
    forward(lawn);
    forward(lawn);
    turnRight(lawn);

    // move cursor to bottom
    cout << "\033[" << LAWN_HEIGHT + 5 << ";1H";
    // make cursor visible
    // cout << "\033[?25h";
    showCursor();

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
                // set north and south walls as red
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

    string str;

    for (int i = lawn.height - 1; i >= 0; i--) {
        // left padding
        cout << "    ";

        for (int j = 0; j < lawn.width; j++) {
            Square current_square = lawn.field[i][j];
            if ((i == lawn.mower.y) && (j == lawn.mower.x)) {
                str = mowerString(lawn);
            } else {
                str = squareString(current_square);
            }
            
            cout << str;
        }
        cout << endl;
    }

    // print mower position info
    moveTo(lawn, -2, 0);
    cout << "Lawn Mower is facing " << getFacing(lawn) << " at " << getPos(lawn) << ".";
    
    // set initial cursor position to lower left
    moveTo(lawn, 1, 1);

}

void moveTo(Field &lawn, int y, int x) {
    
    cout << "\033[" << to_string(lawn.height - y + 2) << ";" << to_string(((x + 2) * 2) + 1) << "H";

}

void savePos() { cout << "\033[s"; }

void restorePos() { cout << "\033[u"; }

void updateMowerPos(Field &lawn) {
    savePos();

    moveTo(lawn, -2, 11);
    // note: extra space at end due to variance in facing text length
    cout << "\b" << getFacing(lawn) << " at " << getPos(lawn) << ". ";

    restorePos();
}

string getFacing(Field &lawn) {
    string facing;

    switch (lawn.mower.facing) {
        case Direction::north:
            facing = "north";
            break;
        case Direction::east:
            facing = "east";
            break;
        case Direction::south:
            facing = "south";
            break;
        case Direction::west:
            facing = "west";
            break;
    }

    return facing;
}

string getPos(Field &lawn) { return "(" + to_string(lawn.mower.x) + ", " + to_string(lawn.mower.y) + ")"; }

string squareString(Square &square) {

    string str;

    switch (square) {
        case Square::red:
            str = "\033[37;41m  \033[0m";
            break;
        case Square::green:
            str = "\033[92;42m\",\033[0m";
            break;
        case Square::visited:
            str = "\033[92;42m .\033[0m";
            break;
        default: // should never happen, but just in case
            str = "\033[33;42m? \033[0m";
            break;
        }

    return str;
}

string mowerString(Field &lawn) {

    string str;

    switch (lawn.mower.facing) {
        case Direction::north:
            str = "\033[30;42m^\033[1C\033[0m";
            break;
        case Direction::east:
            str = "\033[30;42m>\033[1C\033[0m";
            break;
        case Direction::south:
            str = "\033[30;42mv\033[1C\033[0m";
            break;
        case Direction::west:
            str = "\033[30;42m<\033[1C\033[0m";
            break;
        default: // should never happen, but just in case
            str = "\033[33;42m@\033[1C\033[0m";
            break;
    }

    return str;
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

void forward(Field &lawn) {

    if (peek(lawn) == Square::red) {
        // cannot move onto wall Square
        return;
    }

    Sleep(250);

    // print lawn square on old mower position and move cursor back
    cout << squareString(lawn.field[lawn.mower.y][lawn.mower.x]) << "\b\b";

    switch (lawn.mower.facing) {
        case Direction::north:
            lawn.mower.y++;
            cout << "\033[1A"; // cursor up 1 line
            break;
        case Direction::east:
            lawn.mower.x++;
            cout << "\033[2C"; // cursor forward 2 spaces
            break;
        case Direction::south:
            lawn.mower.y--;
            cout << "\033[1B"; // cursor down 1 line
            break;
        case Direction::west:
            lawn.mower.x--;
            cout << "\033[2D"; // cursor back 2 spaces
            break;
        default: // should never happen, but just in case
            return;
    }

    // mark new Square as visited
    lawn.field[lawn.mower.y][lawn.mower.x] = Square::visited;

    // print new mower position
    cout << mowerString(lawn) << "\b\b";

    // update mower position
    updateMowerPos(lawn);

    // return 1 for success
    return;
}

void turnLeft(Field &lawn) {

    Sleep(250);

    /* 
     * Modulo* on a negative number gives a negative (e.g. (-1) % 4 = (-1)).
     * Therefore, instead of (temp - 1) to rotate ccw, I am using (temp + 3)
     * to avoid negative numbers by rotating (4 - 1) cw.
     * 
     * in C/C++, % is actually remainder, not modulo.
     */

    int temp = static_cast<int>(lawn.mower.facing);
    temp = (temp + 3) % 4;

    lawn.mower.facing = static_cast<Direction>(temp);
    
    // print new mower position
    cout << mowerString(lawn) << "\b\b";

    // update mower position
    updateMowerPos(lawn);
}

void turnRight(Field &lawn) {

    Sleep(250);

    int temp = static_cast<int>(lawn.mower.facing);
    temp = (temp + 1) % 4;

    lawn.mower.facing = static_cast<Direction>(temp);
    
    // print new mower position
    cout << mowerString(lawn) << "\b\b";

    // update mower position
    updateMowerPos(lawn);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; // Set cursor visibility to true
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}