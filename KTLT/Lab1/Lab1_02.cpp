#include<iostream>
using namespace std;

int main() {
    int a[3][4];
    int i = 0;
    while(i < 3) {
        int j = 0;
        while(j < 4) {
            cout << "Nhap phan tu a[" << i << ", " << j << "]: ";
            cin >> a[i][j];
            j++;
        }
        i++;
    }
    cout << "Ma tran vua nhap:\n";
    i = 0;
    while(i < 3) {
        int j = 0;
        while(j < 4) {
            cout << a[i][j] << "\t";
            j++;
        }
        cout << "\n\n";
        i++;
    }
    return 0;
}