#include <iostream>

using namespace std;

void CheckFruit() {
    if (x == fruitX && y == fruitY) {
        score += 10; // Tăng điểm khi ăn thức ăn
        fruitX = rand() % width; // Tạo vị trí mới cho thức ăn
        fruitY = rand() % height; // Tạo vị trí mới cho thức ăn
        nTail++; // Tăng chiều dài của con rắn
    }
}

int main() {
    float a,b,delta,x1,x2;

    cout << "Nhap vao a: ";
    cin >> a;
    cout << "Nhap vao b: ";
    cin >> b;


    return 0;
}