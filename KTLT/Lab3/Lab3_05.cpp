#include<iostream>
using namespace std;

void Fibonacci(int *p, int n) {
    p[1] = 1, p[2] = 1;
    for(int i = 3; i <= n; i++) {
        p[i] = p[i - 1] + p[i - 2]; // *(p + i) = *(p + i - 1) + *(p + i - 2)
    }
    cout << n << " gia tri cua day Fibonacci: ";
    for(int i = 1; i <= n; i++) {
        cout << p[i] << " "; // cout << *(p + i) << " "
    }
    cout << "\n";
}
int main() {
    int n;
    do{
        cout << "Nhap so nguyen n (n > 1): ";
        cin >> n;
    }while(n < 2);
    int *p = new int[n + 1];
    Fibonacci(p, n);
    delete[] p;
    return 0;
}