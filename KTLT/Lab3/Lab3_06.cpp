#include<iostream>
using namespace std;

void input(int *&p, int n) {
    p = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << " = ";
        cin >> p[i];
    }
}
void output(int *p, int n) {
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}
void daoNguoc(int *p, int n) {
    for(int i = 0; i < n/2; i++) {
        swap(p[i], p[n - 1- i]);
    }
}
int main() {
    int n;
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    }while(n < 1);
    int *p = new int[n];
    input(p, n);
    cout << "Mang vua nhap: ";
    output(p, n);
    daoNguoc(p, n);
    cout << "Mang dao nguoc: ";
    output(p, n);
    return 0;
}