#include<iostream>
using namespace std;
int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return C(k - 1, n - 1) + C(k, n - 1);
}
int main() {
    int h;
    do{
        cout << "Nhap chieu cao cho tam giac pascal: ";
        cin >> h;
        if(h < 1) cout << "chieu cao cua tam giac toi thieu la 1. Xin nhap lai!\n";
    }while(h < 1);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            cout << C(j, i) << " ";
        }
        cout << endl;
    }
    return 0;
}