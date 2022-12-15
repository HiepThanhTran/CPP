#include<iostream>
#include<cmath>
using namespace std;

void nhap(int **&a, int r, int c) {
    for(int i = 0; i < r; i++) {
        cout << "Nhap " << c << " gia tri cho dong thu " << i + 1 << ": ";
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
}
void xuat(int **a, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
bool SNT(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int *firstPos(int **a, int *p, int r, int c) {
    bool flag = false;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(SNT(a[i][j])) {
                flag = true;
                p[0] = i + 1;
                p[1] = j + 1;
                break;
            }
        }
        if(flag) break;
    }
    return p;
}
int main() {
    int r, c;
    do{
        cout << "Nhap so luong hang: ";
        cin >> r;
        cout << "Nhap so luong cot: ";
        cin >> c;
        if(r < 1 || c < 1) cout << "So luong hang/cot toi thieu la 1!\n";
    }while(r < 1 || c < 1);
    int **a;
    a = new int *[r];
    for(int i = 0; i < r; i++) {
        a[i] = new int[c];
    }
    nhap(a, r, c);
    cout << "Mang vua nhap:\n";
    xuat(a, r, c);
    int *p;
    p = new int[2];
    int *q;
    q = new int[2];
    q = firstPos(a, p, r, c);
    cout << "Vi tri so nguyen to dau tien trong mang la hang " << q[0] << " cot " << q[1] << endl;
    delete[] p;
    delete[] q;
    for(int i = 0; i < r; i++) {
        delete[] a[i];
    }
    delete[] a;
    a = nullptr;
    return 0;
}