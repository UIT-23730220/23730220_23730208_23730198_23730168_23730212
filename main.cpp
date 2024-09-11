#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h> 

// Define game dimensions
#define WIDTH 20
#define HEIGHT 20

// Direction enumerator for movement
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Game state variables
bool gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

void Input();
void Logic();
void createFrame();
void menuGame();
void Score(int& thoat, char name[], int& lever, int score);
void playgame(int& thoat, char name[], int& lever);

int main() {
  
    createFrame();

   
    getch();


    // Kiểm tra va chạm với đuôi
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }
}

void Input() { // TRẦN NHƯ PHONG
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

void Logic() { // NGUYỄN ĐĂNG SANG
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
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
}

void createFrame() { // PHAN NHẬT HÒA
    int x, y;
    for (y = 0; y <= HEIGHT; y++) {
        for (x = 0; x <= WIDTH; x++) {
            if (x == 0 || x == WIDTH) {
                printf("#");
            }
            else if (y == 0 || y == HEIGHT) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void menuGame(){ // NGUYỄN HOÀNG THANH TÚ
    cout << "Chon chuc nang duoc hien thi ben duoi:\n";
    cout << "1. Play!\n";
    cout << "2. Exit.\n";
    int choice;
    cin >> choice;
    switch (choice){
        case 1: 
            break;
        case 2:
            break;
        default:
            cout << "invalid choice.\n" << endl;
            break;
    }
}

void Score(int& thoat, char name[], int& lever, int score) {
    system("cls"); // Xóa màn hình
    
    // Hiển thị thông tin điểm số
    cout << "==================== BANG DIEM ====================" << endl;
    cout << "Tên người chơi: " << name << endl;
    cout << "Cấp độ: " << lever << endl;
    cout << "Điểm cuối cùng: " << score << endl;
    cout << "===================================================" << endl;

    // Hiển thị tùy chọn thoát hoặc chơi lại
    cout << "\nNhấn 'e' để Thoát hoặc 'r' để Chơi lại: ";
    char a = _getch(); // Lấy ký tự nhập từ bàn phím

    if (a == 'e' || a == 'E') {
        thoat = 1; // Đặt cờ thoát
        gameOver = true; // Kết thúc trò chơi
    } 
    else if (a == 'r' || a == 'R') {
        thoat = 0; // Đặt lại cờ thoát
        playgame(thoat, name, lever); // Chơi lại trò chơi
    }

    system("cls"); // Xóa màn hình
}


void playgame(int& thoat, char name[], int& lever){ // NGUYỄN HOÀNG THANH TÚ
  
}
