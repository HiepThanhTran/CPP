#include<iostream>
using namespace std;

int main() {
    int n;
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if(n < 1 || n > 20) cout << "So luong phan tu toi da la 20!\n";
    }while(n < 1 || n > 20);
    int *p = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap phan tu a[" << i << "] = ";
        cin >> p[i];
    }
    cout << "Mang vua nhap:\n";
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    for(int i = 0; i < n/2; i++) {
        swap(p[i], p[n - 1 - i]);
    }
    cout << "\nMang sau khi dao nguoc:\n";
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    delete[] p;
    return 0;
}