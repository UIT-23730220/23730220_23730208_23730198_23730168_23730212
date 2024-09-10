#include <stdio.h>
#include <conio.h>  

#define WIDTH 20   
#define HEIGHT 10  

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

int main() {
  
    createFrame();

   
    getch();

    return 0;
}