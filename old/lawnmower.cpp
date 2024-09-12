#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

// update

enum class Direction { north, east, south, west };

enum class SquareType { red, green, visited };

struct Mower {
    Direction facing;
    int x;
    int y;
    int peeks = 0;
    int turns = 0;
    int steps = 0;
};

struct Field {
    int height;
    int width;
    Mower mower;
    SquareType **field = new SquareType*[height];
};

void initLawn(Field&);
string squareString(SquareType&);
string mowerString(Field&);
void printLawn(Field&);
void moveTo(Field&, int, int);
void savePos();
void restorePos();
void updateMowerPos(Field&);
string getFacing(Field&);
string getPos(Field&);
SquareType peek(Field&);
int forward(Field&);
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
    
    // randomize lawn height and width to 5 - 20 Squares, plus a 1 Square border of walls
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

    // move cursor to bottom
    moveTo(lawn, -5, 0);
    // wait for keypress
    system("pause");
    // delete line
    cout << "\033[" << LAWN_HEIGHT + 6 << ";1H";
    cout << "\033[J";
    // move cursor to bottom left square
    moveTo(lawn, 1, 1);
    

    // orient mower west from bottom left corner
    if (peek(lawn) == SquareType::green) {
        turnRight(lawn);
        if (peek(lawn) != SquareType::green) {
            turnLeft(lawn);
        }
    } else {
        do {
            turnLeft(lawn);
        } while (peek(lawn) != SquareType::green);
    }

    // move to bottom right corner and find width
    int counter = 0;
    while (forward(lawn)) {
        counter++;
    }
    // orient north
    turnLeft(lawn);

    // main loop
    while (forward(lawn)) {
        turnLeft(lawn);
        for (int i = 0; i < counter; i++) {
            forward(lawn);
        }
        turnRight(lawn);
        if (forward(lawn)) {
            turnRight(lawn);
            for (int i = 0; i < counter; i++) {
                forward(lawn);
            }
            turnLeft(lawn);
        } else {
            break;
        }

    }



    
    // move cursor to bottom
    moveTo(lawn, -5, 0);
    // wait for keypress
    system("pause");
    // delete line
    moveTo(lawn, -5, 0);
    cout << "\033[J";

    showCursor();

    return 0;
}

void initLawn(Field &lawn) {

    for (int i = 0; i < lawn.height; i++) {
        // declare array for each row
        lawn.field[i] = new SquareType[lawn.width];
        // set west wall as red
        lawn.field[i][0] = SquareType::red;
        for (int j = 1; j < lawn.width - 1; j++) {
            if ((i == 0) || (i == (lawn.height - 1))) {
                // set north and south walls as red
                lawn.field[i][j] = SquareType::red;
            } else {
                // grassy interior
                lawn.field[i][j] = SquareType::green;
            }
        }
        // set east wall as red
        lawn.field[i][lawn.width - 1] = SquareType::red;
    }

    // set initial Mower position to visited
    lawn.field[1][1] = SquareType::visited;

}

void printLawn(Field &lawn) {

    string str;

    for (int i = lawn.height - 1; i >= 0; i--) {
        // left padding
        cout << "    ";

        for (int j = 0; j < lawn.width; j++) {
            cout << squareString(lawn.field[i][j]);
        }
        cout << endl;
    }

    // print mower position info
    moveTo(lawn, -2, 0);
    cout << "Lawnmower is facing " << getFacing(lawn) << " at " << getPos(lawn);

    // print step counter
    moveTo(lawn, -3, 0);
    cout << "Peeks: " << lawn.mower.peeks << "    Turns: " << lawn.mower.turns << "    Steps: " << lawn.mower.steps;
    
    // set initial cursor position to lower left
    moveTo(lawn, 1, 1);

    // print mower
    cout << mowerString(lawn) << "\b\b";

}

void moveTo(Field &lawn, int y, int x) {
    
    cout << "\033[" << to_string(lawn.height - y + 2) << ";" << to_string(((x + 2) * 2) + 1) << "H";

}

void savePos() { cout << "\033[s"; }

void restorePos() { cout << "\033[u"; }

void updateMowerPos(Field &lawn) {
    savePos();

    moveTo(lawn, -2, 10);
    // note: extra space at end due to variance in facing text length
    cout << getFacing(lawn) << " at " << getPos(lawn) << "  ";

    // print step counter
    moveTo(lawn, -3, 0);
    cout << "Peeks: " << lawn.mower.peeks << "  Turns: " << lawn.mower.turns << "  Steps: " << lawn.mower.steps;

    restorePos();
}

void updateMowerSteps(Field &lawn) {
    savePos();

    // print step counter
    moveTo(lawn, -3, 4);
    cout << lawn.mower.peeks << "\b    Turns: " << lawn.mower.turns << "    Steps: " << lawn.mower.steps;

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

string squareString(SquareType &square) {

    string str;

    switch (square) {
        case SquareType::red:
            str = "\033[37;41m  \033[0m";
            break;
        case SquareType::green:
            switch (rand() %2) {
                case 0:
                    str = "\033[37;42m\",\033[0m";
                    break;
                default:
                    str = "\033[37;42m,\"\033[0m";
                    break;
            }
            break;
        case SquareType::visited:
            str = "\033[37;42m .\033[0m";
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

SquareType peek(Field &lawn) {

    lawn.mower.peeks++;

    SquareType next;

    // no bounds checking because lawnmower will never be on a wall square
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

    updateMowerSteps(lawn);

    return next;
}

int forward(Field &lawn) {

    Sleep(100);
    lawn.mower.steps++;

    if (peek(lawn) == SquareType::red) {
        // shouldn't count towards peek actions
        lawn.mower.peeks--;
        // cannot move onto wall Square
        updateMowerSteps(lawn);
        return 0;
    } else {
        // shouldn't count towards peek actions
        lawn.mower.peeks--;
    }

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
            return 0;
    }

    // mark new Square as visited
    lawn.field[lawn.mower.y][lawn.mower.x] = SquareType::visited;

    // print new visited lawn square
    cout << squareString(lawn.field[lawn.mower.y][lawn.mower.x]) << "\b\b";

    // print new mower position
    cout << mowerString(lawn) << "\b\b";

    // update mower position
    updateMowerPos(lawn);
    // update mower steps
    updateMowerSteps(lawn);

    return 1;
}

void turnLeft(Field &lawn) {

    Sleep(100);
    lawn.mower.turns++;

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
    // update mower steps
    updateMowerSteps(lawn);
}

void turnRight(Field &lawn) {

    Sleep(100);
    lawn.mower.turns++;

    int temp = static_cast<int>(lawn.mower.facing);
    temp = (temp + 1) % 4;

    lawn.mower.facing = static_cast<Direction>(temp);
    
    // print new mower position
    cout << mowerString(lawn) << "\b\b";

    // update mower position
    updateMowerPos(lawn);
    // update mower steps
    updateMowerSteps(lawn);
}

// got code to hide/show cursor in cmd.exe on Windows from chatGPT

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