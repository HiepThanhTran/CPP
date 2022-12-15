#include<iostream>
using namespace std;

int UCLN(int a, int b) {
    if(b == 0) return a;
    return UCLN(b, a % b);
}
int main() {
    int a, b;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << UCLN(a, b) << endl;
    return 0;
}