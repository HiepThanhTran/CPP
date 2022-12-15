#include<iostream>
#include<cmath>
using namespace std;

bool SNT(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int main() {
    int r, c;
    do{
        cout << "Nhap so luong hang: ";
        cin >> r;
    }while(r < 1);
    do{
        cout << "Nhap so luong cot: ";
        cin >> c;
    }while(c < 1);
    int **a;
    a = new int *[r];
    for(int i = 0; i < r; i++) {
        a[i] = new int[c];
    }
    for(int i = 0; i < r; i++) {
        cout << "Nhap " << c << " gia tri cho dong thu " << i + 1 << ": ";
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Mang vua nhap:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
    int count = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(SNT(a[i][j])) count++;
        }
    }
    cout << "Co " << count << " so nguyen to trong mang\n";
    return 0;
}