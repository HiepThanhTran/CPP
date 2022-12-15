#include<iostream>
using namespace std;
const int MAX = 50;

int main() {
    int a[MAX][MAX];
    int n;
    do {
        cout << "Nhap cap cua ma tran vuong: ";
        cin >> n;
        if(n < 1 || n > MAX) cout << "Cap ma tran khong hop le!\n";
    }while(n < 1 || n > MAX);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Nhap a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    cout << "Ma tran vua nhap:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
    int mainCross = 0, sideCross = 0;
    for(int i = 0; i < n; i++) {
        mainCross += a[i][i];
    }
    for(int i = 0; i < n; i++) {
        sideCross += a[i][n - 1 - i];
    }
    cout << "Tong cac phan tu tren duong cheo chinh = " << mainCross << endl;
    cout << "Tong cac phan tu tren duong cheo phu = " << sideCross << endl;
    return 0;
}