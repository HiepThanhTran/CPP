#include<iostream>
using namespace std;

int demChuSo(int n) {
    if(n < 10) return 1;
    return 1 + demChuSo(n / 10);
}
int main() {
    int n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
    }while(n < 1);
    cout << "So luong chu so cua " << n << " la: " << demChuSo(n) << endl;
    return 0;
}