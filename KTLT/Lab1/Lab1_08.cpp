#include<iostream>
using namespace std;
const int MAX = 50;

void nhapMang(int a[][MAX], int n) {
    cout << "\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Nhap phan tu [" << i << "][" << j <<"] = ";
            cin >> a[i][j];
        }
    }
    cout << "\n";
}
void xuatMang(int a[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
void tong2MaTran(int a[][MAX], int b[][MAX], int n) {
    int Tong[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Tong[i][j] = a[i][j] + b[i][j];
        }
    }
    xuatMang(Tong, n);
}
void tich2MaTran(int a[][MAX], int b[][MAX], int n) {
    int Tich[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Tich[i][j] = {0};
            for(int k = 0; k < n; k++) {
                Tich[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    xuatMang(Tich, n);
}
int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int n;
    do {
        cout << "Nhap cap cua ma tran: ";
        cin >> n;
        if(n < 1 || n > MAX) cout << "Khong hop le!\n";
    }while(n < 1 || n > MAX);
    cout << "Nhap ma tran thu 1:\n";
    nhapMang(a, n);
    cout << "Nhap ma tran thu 2:\n";
    nhapMang(b, n);
    cout << "Xuat 2 ma tran vua nhap\n";
    cout << "Ma tran thu 1:\n";
    xuatMang(a, n);
    cout << "Ma tran thu 2:\n";
    xuatMang(b, n);
    cout << "Tong 2 ma tran:\n";
    tong2MaTran(a, b, n);
    cout << "Tich 2 ma tran:\n";
    tich2MaTran(a, b, n);
    return 0;
}