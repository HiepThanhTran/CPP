#include<iostream>
using namespace std;
const int MAXR = 50, MAXC = 50;

void nhapMang(int a[][MAXC], int row, int col) {
    cout << "\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "\n";
}
void xuatMang(int a[][MAXC], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
int trungBinh(int a[][MAXC], int row, int col) {
    int sum = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            sum += a[i][j];
        }
    }
    return sum / (row * col);
}
bool kiemTra(int a[][MAXC], int &index1, int &index2, int row, int col, int x) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(x == a[i][j]) {
                index1 = i;
                index2 = j;
                return true;
            }
        }
    }
    return false;
}
void swapXY(int a[][MAXC], int row, int col, int &x, int &y) {
    int ix, jx, iy, jy;
    do{
        cout << "Nhap gia tri x: ";
        cin >> x;
        if(!kiemTra(a, ix, jx, row, col, x)) cout << "\nGia tri x phai ton tai trong mang. Xin nhap lai!\n";
    }while(!kiemTra(a, ix, jx, row, col, x));
    do{
        cout << "Nhap gia tri y: ";
        cin >> y;
        if(!kiemTra(a, iy, jy, row, col, y)) cout << "\nGia tri y phai ton tai trong mang. Xin nhap lai!\n";
    }while(!kiemTra(a, iy, jy, row, col, y));
    swap(a[ix][jx], a[iy][jy]);
}
long long tinhTich(int a[][MAXC], int row, int col) {
    int tich = 1;
    for(int i = 0; i < row; i++) {
        tich *= a[i][col];
    }
    return tich;
}
int main() {
    int a[MAXR][MAXC];
    int aR, aC, x, y;
    do {
        cout << "Nhap so luong dong: ";
        cin >> aR;
        if(aR < 1 || aR > MAXR) cout << "Khong hop le!\n";
    }while(aR < 1 || aR > MAXR);
    do {
        cout << "Nhap so luong cot: ";
        cin >> aC;
        if(aC < 1 || aC > MAXC) cout << "Khong hop le!\n";
    }while(aC < 1 || aC > MAXC);
    nhapMang(a, aR, aC);
    cout << "Mang vua nhap:\n";
    xuatMang(a, aR, aC);
    int result1 = trungBinh(a, aR, aC);
    cout << "Gia tri trung binh cua tat ca phan tu trong mang = " << result1 << endl;
    swapXY(a, aR, aC, x, y);
    cout << "Mang sau khi doi 2 gia tri x = " << x << " va y = " << y << ":\n";
    xuatMang(a, aR, aC);
    int col;
    do{
        cout << "Nhap vi tri cot can tinh tich: ";
        cin >> col;
        if(col < 0 || col >= aC) cout << "Vi tri cot khong hop le!\n";
    }while(col < 0 || col >= aC);
    int result2 = tinhTich(a, aR, col);
    cout << "Tich cac gia tri tren cot " << col << " = " << result2 << endl;
    return 0;
}