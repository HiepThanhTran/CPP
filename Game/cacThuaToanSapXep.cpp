#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;
int setColorX = 11,
    setColorY = 14,
    setColorN = 15,
    setColorMin = 13,
    setX = 30, setY = 17;
    
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
void DoThi(int *a, int n, int x, int y, int min, int d){
	if(d == 1)
	    for(int i=0; i<n; i++){
	        if(i == x)
	            TextColor(setColorX);
	        else if(i == y)
	            TextColor(setColorY);
	        else if(i == min)
	            TextColor(setColorMin);
	        else
	        	TextColor(setColorN);
	        gotoXY(setX + i*3, setY + 2);
	        cout << a[i];
	        for(int j=1; j<=a[i]; j++){
	            gotoXY(setX + i*3, setY - j);
	            cout << char (219);
	        }
	    }
	else
		for(int i=0; i<n; i++){
			gotoXY(setX + i*3, setY + 2);
			cout << "   ";
	        for(int j=1; j<=setY - 3; j++){
	            gotoXY(setX + i*3, setY - j);
	            cout << " ";
	        }
	    }
}
void SelectionSort(int* a, int n){
	DoThi(a, n, -1, -1, -1, 1);
	gotoXY(setX + n*3/2 - 10, setY + 1);
	cout << "Selection - ducvu25 - UET";
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
        	if(a[j] < a[min])
                min = j;
            DoThi(a, n, i, j, min, 0);
            DoThi(a, n, i, j, min, 1);
            Sleep(150);
		}
        if(a[min] < a[i]){
            int t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
        DoThi(a, n, i, -1, min, 0);
        DoThi(a, n, i, -1, min, 1);
        Sleep(250);
    }
    DoThi(a, n, -1, -1, -1, 1);
}
void Cout(int* a, int n){
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main(){
    int n;
    int* a = Input(n);
    cout << "\nTruoc:\n";
    Cout(a, n);
    SelectionSort(a, n);
    cout << "\nSau:\n";
    Cout(a, n);

}
