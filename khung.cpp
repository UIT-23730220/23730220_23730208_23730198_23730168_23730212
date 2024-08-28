#include <iostream>
#include <conio.h>  // For _kbhit() and _getch() on Windows
#include <windows.h>  // For Sleep() on Windows
using namespace std;

// Game area size
const int width = 20;
const int height = 20;

// Snake variables
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Draw the game box
void drawBox() {
    system("cls");  // Clear the console

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";  // Draw left wall
            if (i == y && j == x)
                cout << "O";  // Draw snake head
            else if (i == fruitY && j == fruitX)
                cout << "F";  // Draw fruit
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";  // Draw snake body
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";  // Draw right wall
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

// Input function
void input() {
    if (_kbhit()) {  // Check if a key is pressed
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': exit(0);  // Exit game
        }
    }
}

// Game logic function
void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    // Wrap around screen (optional)
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // If the snake collides with itself
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            exit(0);  // End the game

    // If the snake eats the fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

// Main function
int main() {
    // Initialize game variables
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    dir = STOP;

    // Main game loop
    while (true) {
        drawBox();
        input();
        logic();
        Sleep(100);  // Slow down the game loop
    }

    return 0;
}