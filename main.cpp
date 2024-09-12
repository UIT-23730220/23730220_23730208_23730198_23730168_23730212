#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h> 

using namespace std;

// Định nghĩa kích thước trò chơi
#define WIDTH 20
#define HEIGHT 20

// Khai báo các hướng di chuyển
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Các biến trạng thái của trò chơi
bool gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

void Input();
void CheckFruit();
void Logic();
void createFrame();
void menuGame();
void Score(int& thoat, char name[], int& lever, int score);
void playgame(int& thoat, char name[], int& lever);

int main() {
    // Ví dụ về dữ liệu người chơi
    int thoat = 0;  // Cờ thoát
    char name[20] = "Player1";  // Tên người chơi
    int lever = 1;  // Mức độ ban đầu

    // Bắt đầu trò chơi
    playgame(thoat, name, lever);

    return 0;
}

void Input() { // TRẦN NHƯ PHONG
    if (_kbhit()) { // Kiểm tra xem có phím nào được nhấn không
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

void CheckFruit() {
    if (x == fruitX && y == fruitY) {
        score += 10; // Tăng điểm khi ăn thức ăn
        fruitX = rand() % WIDTH; // Tạo vị trí mới cho thức ăn
        fruitY = rand() % HEIGHT; // Tạo vị trí mới cho thức ăn
        nTail++; // Tăng chiều dài của con rắn
    }
}

void Logic() { // NGUYỄN ĐĂNG SANG
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x; // Lưu vị trí đầu con rắn
    tailY[0] = y;

    // Cập nhật vị trí đuôi con rắn
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Cập nhật vị trí đầu con rắn dựa trên hướng di chuyển
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

    // Xử lý khi chạm biên màn hình
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    // Kiểm tra va chạm với đuôi
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    CheckFruit(); // Kiểm tra xem có ăn thức ăn không
}

void createFrame() {
    system("cls"); // Xóa màn hình console
    for (int i = 0; i < WIDTH + 2; i++) cout << "#"; // Viền trên
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) cout << "#"; // Viền bên trái

            if (i == y && j == x) cout << "O"; // Đầu con rắn
            else if (i == fruitY && j == fruitX) cout << "F"; // Thức ăn
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // Đuôi con rắn
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }

            if (j == WIDTH - 1) cout << "#"; // Viền bên phải
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++) cout << "#"; // Viền dưới
    cout << endl;

    cout << "Diem: " << score << endl;
}

void menuGame() { // NGUYỄN HOÀNG THANH TÚ
    cout << "Chon mot tuy chon:\n";
    cout << "1. Choi!\n";
    cout << "2. Thoat.\n";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        // Bắt đầu trò chơi
        break;
    case 2:
        gameOver = true; // Thoát trò chơi
        break;
    default:
        cout << "Lua chon khong hop le.\n";
        break;
    }
}

void Score(int& thoat, char name[], int& lever, int score) {
    // PHẠM PHƯƠNG HỒNG NGỮ Hiển thị thông tin điểm số
    system("cls"); // Xóa màn hình
    cout << "==================== BANG DIEM ====================" << endl;
    cout << "Ten nguoi choi: " << name << endl;
    cout << "Cap do: " << lever << endl;
    cout << "Diem cuoi cung: " << score << endl;
    cout << "===================================================" << endl;

    // Hiển thị tùy chọn thoát
    cout << "\nNhan 'e' de Thoat hoac 'r' de Choi lai: ";

    char a;
    a = _getch(); // Lấy ký tự nhập từ bàn phím

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

void playgame(int& thoat, char name[], int& lever) { // NGUYỄN HOÀNG THANH TÚ
    menuGame();
    // Khởi tạo các biến trò chơi
    gameOver = false;
    dir = STOP;
    x = WIDTH / 2;      // Vị trí đầu con rắn ban đầu
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;   // Vị trí ngẫu nhiên của thức ăn
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;          // Chiều dài ban đầu của đuôi con rắn

    // Vòng lặp trò chơi
    while (!gameOver) {
        createFrame();  // Vẽ khung trò chơi
        Input();        // Xử lý nhập liệu từ người chơi
        Logic();        // Cập nhật logic trò chơi
        Sleep(100);     // Điều chỉnh tốc độ trò chơi (độ trễ tính bằng mili giây)
    }

    // Hiển thị điểm cuối cùng sau khi trò chơi kết thúc
    Score(thoat, name, lever, score);
}
