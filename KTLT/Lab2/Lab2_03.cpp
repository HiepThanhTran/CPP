#include<iostream>
using namespace std;

long long Fibonacci(int n) {
    if(n == 1 || n == 2) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main() {
    int n;
    do{
        cout << "Nhap n : ";
        cin >> n;
    }while(n < 1);
    cout << "So Fibonacci thu " << n << " = " << Fibonacci(n) << endl;
    return 0;
}