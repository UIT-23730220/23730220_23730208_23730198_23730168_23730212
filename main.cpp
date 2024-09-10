#include <iostream>

using namespace std;

void menuGame();

int main() {
    float a,b,delta,x1,x2;

    cout << "Nhap vao a: ";
    cin >> a;
    cout << "Nhap vao b: ";
    cin >> b;


    return 0;
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
};