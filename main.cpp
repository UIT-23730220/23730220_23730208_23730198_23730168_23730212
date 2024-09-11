
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h> 


#define WIDTH 20   
#define HEIGHT 20  


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

// Hàm tạo khung
void createFrame() {
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

void menuGame();
void Score();

int main() {
  
    createFrame();

   
    getch();


    // Kiểm tra va chạm với đuôi
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }
}

void menuGame(){
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
void Score(int &thoat, char name[], int &lever, Snake &luusnake, char dname[])
{
  khungplay();
  gotoxy(34, 0); TextColor(160); printf(" HIGHT SCORE ");
  TextColor(0);
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 11); printf(" ");
    }
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 21); printf(" ");
    }
 gotoxy(33, 6); TextColor(12); printf("DIEM CAO NHAT");  
 gotoxy(25, 8); TextColor(11); printf("Ten Nguoi Choi:");       gotoxy(41, 8); TextColor(15); printf("%s", dname);
 gotoxy(25, 9); TextColor(11); printf("Diem Cao:");             gotoxy(41, 9); TextColor(10); printf("%d", luusnake.n);
    gotoxy(36,36); TextColor(47); printf("  EXIT  ");
    gotoxy(39,36);
    TextColor(0);
 char a;
    do
    {
        a = getch();
    }while(a!=13 && a != 'e' && a != 'E' && a !='5' && a != 8);
    system("cls");
    fflush(stdin);
    playgame(thoat, name, lever, luusnake, dname);  
}
