#include<iostream>
using namespace std;

void nhapMaTran(int a[5][6], int aRow, int aCol) {
    cout << "\n";
    for(int i = 0; i < aRow; i++) {
        for(int j = 0; j < aCol; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\n";
}
void xuatMaTran(int a[5][6], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
int sumOfRow(int a[5][6], int row, int aCol) {
    int sum = 0;
    for(int i = 0; i < aCol; i++) {
        sum += a[row][i];
    }
    return sum;
}
int sumOfCol(int a[5][6], int aRow, int col) {
    int sum = 0;
    for(int i = 0; i < aRow; i++) {
        sum += a[i][col];
    }
    return sum;
}

/* 
1   2   1   5

3   5   6   4

1   1   3   2

x = 2
Xuất hiện 2 lần
Lần 1 : Hàng 0 cột 1
Lần 2 : Hàng 2 cột 3
*/

bool check(int a[5][6], int aRow, int aCol, int x) {
    for(int i = 0; i < aRow; i++) {
        for(int j = 0; j < aCol; j++) {
            if(x == a[i][j]) {
                return true;
            }
        }
    }
    return false;
}
void findX(int a[5][6], int aRow, int aCol, int x) {
    int viTriI[30], viTriJ[30];
    int count = 0;
    for(int i = 0; i < aRow; i++) {
        for(int j = 0; j < aCol; j++) {
            if(x == a[i][j]) {
                count++;
                viTriI[count] = i;
                viTriJ[count] = j;
            }
        }
    }
    cout << "Gia tri " << x << " xuat hien " << count << " lan o cac vi tri:\n";
    for(int i = 1; i <= count; i++) {
        cout << "Hang " << viTriI[i] << ", cot " << viTriJ[i] << endl;
    }
}
int main() {
    int a[5][6];
    int aRow, aCol;
    do{
        cout << "Nhap so luong hang: ";
        cin >> aRow;
        if(aRow < 1 || aRow > 5) cout << "Khong hop le!\n";
    }while(aRow < 1 || aRow > 5);
    do{
        cout << "Nhap so luong cot: ";
        cin >> aCol;
        if(aCol < 1 || aCol > 6) cout << "Khong hop le!\n";
    }while(aCol < 1 || aCol > 6);
    nhapMaTran(a, aRow, aCol);
    cout << "Ma tran vua nhap:\n";
    xuatMaTran(a, aRow, aCol);
    int row, col, op;
    do{
        cout << "(1): Tinh tong cac hang\n(2): Tinh tong cac cot\n";
        cin >> op;
        if(op != 1 && op != 2) cout << "Lua chon khong hop le!\n";
    }while(op != 1 && op != 2);
    switch(op) {
        case 1:
            {
                do{
                    cout << "Nhap hang can tinh tong: ";
                    cin >> row;
                    if(row < 0 || row >= aRow) cout << "Khong hop le!\n";
                }while(row < 0 || row >= aRow);
                int result = sumOfRow(a, row, aCol);
                cout << "Tong hang " << row << " = " << result << endl;
                break;
            }
        case 2:
            {
                do{
                    cout << "Nhap cot can tinh tong: ";
                    cin >> col;
                    if(col < 0 || col >= aCol) cout << "Khong hop le!\n";
                }while(col < 0 || col >= aCol);
                int result = sumOfCol(a, aRow, col);
                cout << "Tong cot " << col << " = " << result << endl;
                break;
            }
    }
    int x;
    cout << "Nhap mot gia tri x bat ky: ";
    cin >> x;
    if(check(a, aRow, aCol, x)) {
        findX(a, aRow, aCol, x);
    }else{
        cout << "Khong tim thay gia tri " << x << endl;
    }
    return 0;
}