#include <iostream>

using namespace std;

int main() {
    float a,b,delta,x1,x2;

    cout << "Nhap vao a: ";
    cin >> a;
    cout << "Nhap vao b: ";
    cin >> b;


    return 0;
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