#include<iostream>
using namespace std;

double luyThua(int x, int n) {
    if(n == 1) return x;
    if(n == -1) return 1.0/x;
    if(n > 0) return x * luyThua(x, n - 1);
    return 1.0/x * luyThua(x, n + 1);
}
int main() {
    int x, n;
    cout << "Nhap he so x: ";
    cin >> x;
    cout << "Nhap so mu: ";
    cin >> n;
    cout << "Ket qua " << x << " ^ " << n << " = " << luyThua(x, n) << endl;
    return 0;
}