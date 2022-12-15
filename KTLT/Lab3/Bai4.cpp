#include<iostream>
using namespace std;

void nhap(int *&a, int n) {
    a = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap phan tu a[" << i << "] = ";
        cin >> a[i];
    }
}
void xuat(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
bool check(int *a, int n) {
    for(int i = 0; i < n/2; i++) {
        if(a[i] != a[n - 1 - i]) return false;
    }
    return true;
}
int main() {
    int n;
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if(n < 1 || n > 15) cout << "So luong phan tu toi da la 15!\n";
    }while(n < 1 || n > 15);
    int *p = new int[n];
    nhap(p, n);
    cout << "Mang vua nhap: ";
    xuat(p, n);
    if(check(p, n)) {
        cout << "La mang doi xung\n";
    }else{
        cout << "Khong phai mang doi xung\n";
    }
    delete[] p;
    return 0;
}