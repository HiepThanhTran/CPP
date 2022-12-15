#include<iostream>
using namespace std;

int S1(int n) {
    if(n == 1) return 1;
    return n + S1(n - 1);
}
long long S2(int n) {
    if(n == 1) return 1;
    return n*n + S2(n - 1);
}
double S3(int n) {
    if(n == 1) return 1;
    if(n % 2 == 0) return S3(n - 1);
    return 1.0/n + S3(n - 1);
}
long long S4(int n) {
    if(n == 1) return 1;
    return n * S4(n - 1);
}
int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "S1 = " << S1(n) << endl;
    cout << "S2 = " << S2(n) << endl;
    cout << "S3 = " << S3(n) << endl;
    cout << "S4 = " << S4(n) << endl;
    return 0;
}