#include<iostream>
using namespace std;

int main() {
    int n;
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if(n < 1 || n > 30) cout << "So luong phan tu toi da la 30!\n";
    }while(n < 1 || n > 30);
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "Mang vua nhap: ";
    for(int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << "\n";
    cout << "Cac phan tu la so le trong mang: ";
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != 0) cout << *(a + i) << " ";
    }
    cout << "\n";
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max) max = a[i];
    }
    cout << "Dia chi cua phan tu lon nhat trong mang: " << &max << endl;
    delete[] a;
    return 0;
}