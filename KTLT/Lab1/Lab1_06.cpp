#include<iostream>
#define MAXR 50
#define MAXC 50
using namespace std;

void nhapMaTran(int a[][MAXC], int row, int col) {
    cout << "\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\n";
}
void xuatMaTran(int a[][MAXC], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
void tongMaTran(int a[][MAXC], int b[][MAXC], int row, int col) {
    int c[MAXR][MAXC];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    xuatMaTran(c, row, col);
}
void tichMaTran(int a[][MAXC], int b[][MAXC], int aR, int bC, int n) {
    int c[MAXR][MAXC];
    for(int i = 0; i < aR; i++) {
        for(int j = 0; j < bC; j++) {
            c[i][j] = {0};
            for(int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    xuatMaTran(c, aR, bC);
}
int main() {
    int a[MAXR][MAXC], b[MAXR][MAXC];
    int aR, aC, bR, bC;
    do{
        cout << "- Nhap so luong hang ma tran A: ";
        cin >> aR;
        if(aR < 1 || aR > MAXR) cout << "Khong hop le!\n";
    }while(aR < 1 || aR > MAXR);
    do{
        cout << "- Nhap so luong cot ma tran A: ";
        cin >> aC;
        if(aC < 1 || aC > MAXC) cout << "Khong hop le!\n";
    }while(aC < 1 || aC > MAXC);
    nhapMaTran(a, aR, aC);
    do{
        cout << "- Nhap so luong hang ma tran B: ";
        cin >> bR;
        if(bR < 1 || bR > MAXR) cout << "Khong hop le!\n";
    }while(bR < 1 || bR > MAXR);
    do{
        cout << "- Nhap so luong cot ma tran B: ";
        cin >> bC;
        if(bC < 1 || bC > MAXC) cout << "Khong hop le!\n";
    }while(bC < 1 || bC > MAXC);
    nhapMaTran(b, bR, bC);
    cout << "Ma tran A vua nhap:\n";
    xuatMaTran(a, aR, aC);
    cout << "Ma tran B vua nhap:\n";
    xuatMaTran(b, bR, bC);
    if(aR == bR && aC == bC) {
        cout << "Tong 2 ma tran A va B:\n";
        tongMaTran(a, b, aR, aC);
    }else{
        cout << "Khong the cong 2 ma tran\n";
    }
    if(aC == bR) {
        cout << "Tich 2 ma tran A va B:\n";
        tichMaTran(a, b, aR, bC, aC);
    }else{
        cout << "Khong the nhan 2 ma tran\n";
    }
    return 0;
}