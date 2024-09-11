#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT; // Di chuyển sang trái
            break;
        case 'd':
            dir = RIGHT; // Di chuyển sang phải
            break;
        case 'w':
            dir = UP; // Di chuyển lên
            break;
        case 's':
            dir = DOWN; // Di chuyển xuống
            break;
        case 'x':
            gameOver = true; // Dừng trò chơi
            break;
        }
    }
}
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x; // Lưu vị trí đầu rắn
    tailY[0] = y;

    // Cập nhật vị trí đuôi rắn
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Cập nhật vị trí đầu rắn dựa trên hướng
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Giới hạn vị trí rắn
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // Kiểm tra va chạm với đuôi
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }
}
int main() {
   
    return 0;
}
