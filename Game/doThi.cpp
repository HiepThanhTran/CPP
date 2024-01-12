#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;
int setColorX = 11,
    setColorY = 14,
    setColorN = 15,
    setX = 30, setY = 15;
void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void gotoXY (int i, int j){
	COORD coord;
	coord.X = i;
	coord.Y = j;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int* Input(int &n){
    ifstream cin("./input.txt");
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    return a;
}
void DoThi(int *a, int n, int x, int y){
    for(int i=0; i<n; i++){
        if(i == x)
            TextColor(setColorX);
        else if(i == y)
            TextColor(setColorY);
        else    
            TextColor(setColorN);
        for(int j=1; j<=a[i]; j++){
            gotoXY(setX + i*2, setY - j);
            cout << char (219);
        }
    }
}
int main(){
    int n;
    int* a = Input(n);
    DoThi(a, n, 1, 2);
    getch();
    return 0;
}
