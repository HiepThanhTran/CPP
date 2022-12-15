#include<iostream>
using namespace std;

int UCLN(int a, int b) {
    if(b == 0) return a;
    return UCLN(b, a % b);
}
int main() {
    int *p = new int;
    int *q = new int;
    cout << "Nhap so thu 1: ";
    cin >> *p;
    cout << "Nhap so thu 2: ";
    cin >> *q;
    cout << "Uoc chung lon nhat cua " << *p << " va " << *q << " la " << UCLN(*p, *q) << endl;
    delete p;
    delete q;
    return 0;
}