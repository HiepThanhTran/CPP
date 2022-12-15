#include<iostream>
using namespace std;

void nhapMaTran(int a[10][15], int row, int col) {
    cout << "\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\n";
}
int Sum(int a[10][15], int row, int col) {
    int sum = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}
void findMin(int a[10][15], int row, int col) {
    int min = a[0][0];
    int iRow = 0, iCol = 0;
    for(int i = 1; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(a[i][j] < min) {
                min = a[i][j];
                iRow = i;
                iCol = j;
            }
        }
    }
    cout << "Gia tri nho nhat trong ma tran = " << min << endl;
    cout << "Gia tri " << min << " nam o hang " << iRow << ", cot " << iCol << endl;
}
void findMax(int a[10][15], int row, int col) {
    int max = a[0][0];
    int iRow = 0, iCol = 0;
    for(int i = 1; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(a[i][j] > max) {
                max = a[i][j];
                iRow = i;
                iCol = j;
            }
        }
    }
    cout << "Gia tri lon nhat trong ma tran = " << max << endl;
    cout << "Gia tri " << max << " nam o hang " << iRow << ", cot " << iCol << endl;
}
int main() {
    int a[10][15];
    int row, col;
    do{
        cout << "Nhap so luong dong: ";
        cin >> row;
        if(row < 1 || row > 10) cout << "Khong hop le!\n";
    }while(row < 1 || row > 10);
    do{
        cout << "Nhap so luong cot: ";
        cin >> col;
        if(col < 1 || col > 15) cout << "Khong hop le!\n";
    }while(col < 1 || col > 15);
    nhapMaTran(a, row, col);
    int result = Sum(a, row, col);
    cout << "Tong cac gia tri luu tru trong ma tran = " << result << endl;
    findMin(a, row, col);
    findMax(a, row, col);
    return 0;
}