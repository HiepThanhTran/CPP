#include <iostream>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

int setupX = 15;
int setupY = 15;
int setColorA = 11;
int setColorB = 12;
int setColorC = 14;
int setColorDau = 5;
int setColorCuoi = 5;
int setColorChon = 7;
int maxx = 4;

void TextColor(int color);
void gotoXY(int x, int y);
void VeThap(vector <int> A, int color, int x, int y);
void VeHinh(vector <int> A, vector <int> B, vector <int> C);
int ketThuc(vector <int> A);
void ThaoTac(vector <int> A, vector <int> B, vector <int> C);
void End();
void Bot(int n, char A, char B, char C);
void Boot(int x, vector <int> &A, vector <int> &B, vector <int> &C);
int main() {
    gotoXY(setupX + 35, setupY + 3); cout << "Thap HN - Trung Duc - K66 - UET";
    vector <int> A, B, C;
    gotoXY(setupX + 40, setupY + 4);
    cout << "Nhap so tang cua thap: "; cin >> maxx;
    for (int i = 1; i <= maxx; i++)
        A.push_back(i * 2);
    VeHinh(A, B, C);
//	Boot(3, A, B, C);
    ThaoTac(A, B, C);
    return 0;
}
void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void VeThap(vector <int> A, int color, int x, int y) {
    TextColor(color);
    gotoXY(x, y); cout << "--------------------"; // 20
    for (int i = 0; i <= 10; i++) {
        if (i < A.size()) {
            for (int j = 0; j < A[i] / 2; j++) {
                gotoXY(x + 10 + j, y - A.size() + i); cout << "=";
                gotoXY(x + 10 - j, y - A.size() + i); cout << "=";
            }
        }
        else {
            gotoXY(x, y - 1 - i); cout << "          |         ";
        }
    }
}
void VeHinh(vector <int> A, vector <int> B, vector <int> C) {
    VeThap(A, setColorA, setupX + 0, setupY);
    VeThap(B, setColorB, setupX + 40, setupY);
    VeThap(C, setColorC, setupX + 80, setupY);
}
int ketThuc(vector <int> A) {
    if (A.size() == 0)
        return 0;
    for (int i = 0; i < A.size() - 1; i++)
        if (A[i] > A[i + 1])
            return 1;
    return 0;
}
void End(int d) {
	gotoXY(setupX + 50, setupY - 5);
	if(d == 1)
		cout << "You win";
	else	
    	cout << "Game over";
}
void ThaoTac(vector <int> A, vector <int> B, vector <int> C) {
    int dau = 0, vitri = 1;
    char c;
    VeThap(A, setColorChon, setupX + 0, setupY);
    while (1) {
        if (_kbhit()) {
            c = _getch();
            switch (c) {
            case 'a': {
                vitri--;
                if (vitri == 0)
                    vitri = 3;
                break;
            }
            case 'd': {
                vitri++;
                if (vitri == 4)
                    vitri = 1;
                break;
            }
            case 'h':{
            	gotoXY(0, setupY + 3); cout << "Goi y:\n";
    			Bot(maxx, 'A', 'B', 'C');
				break;
			}
            case 's': {
                if (dau != 0) {
                    int tam;
                    switch (dau) {
                    case 1: {
                        tam = A[0];
                        A.erase(A.begin());
                        break;
                    }
                    case 2: {
                        tam = B[0];
                        B.erase(B.begin());
                        break;
                    }
                    case 3: {
                        tam = C[0];
                        C.erase(C.begin());
                        break;
                    }
                    }
                    switch (vitri) {
                    case 1: {
                        A.insert(A.begin(), tam);
                        break;
                    }
                    case 2: {
                        B.insert(B.begin(), tam);
                        break;
                    }
                    case 3: {
                        C.insert(C.begin(), tam);
                        break;
                    }
                    }
                    dau = 0;
                }
                else {
                    if ((vitri == 1 && A.size() == 0) || (vitri == 2 && B.size() == 0) || (vitri == 3 && C.size() == 0))
                        goto thoat;
                    else
                        dau = vitri;
                }
            }
            }
        thoat:
            VeHinh(A, B, C);
            switch (vitri) {
            case 1: {
                VeThap(A, setColorChon, setupX + 0, setupY);
                break;
            }
            case 2: {
                VeThap(B, setColorChon, setupX + 40, setupY);
                break;
            }
            case 3: {
                VeThap(C, setColorChon, setupX + 80, setupY);
            }
            }
            if (ketThuc(A) == 1 || ketThuc(B) == 1 || ketThuc(C) == 1) {
                        End(0);
                        return;
                    }
			if(C.size() == maxx){
				End(1);
				return;
			}
        }
    }
}
void Boot(int x, vector <int> &A, vector <int> &B, vector <int> &C){
	if(x == 1){
		C.insert(C.begin(), A[0]);
		A.erase(A.begin());
		VeHinh(A, B, C);
		Sleep(1000);
	}else{
		Boot(x - 1, A, C, B);
		Boot(1, A, B, C);
		Boot(x - 1, B, A, C);
	}
}
void Bot(int n, char nguon, char trungGian, char dich){
	if(n == 1){
		cout << nguon << "-->" << dich << endl;
	}else{
		Bot(n-1, nguon, dich, trungGian);
		Bot(1, nguon, trungGian, dich);
		Bot(n - 1, trungGian, nguon, dich);
	}
}

/*
3

*/
