#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int n, a[30];
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    }while(n < 1 || n > 30);
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }
    int *p = a;
    cout << "Mang vua nhap (Theo ky phap do doi): ";
    for(int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << "\n";
    cout << "Mang vua nhap (Theo ky phap chi so): ";
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
    return 0;
}