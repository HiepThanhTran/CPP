#include<iostream>

using namespace std;

void swap
(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a, b, c;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;
    cout << "Nhap so nguyen c: ";
    cin >> c;
    if(a<b) {
        swap
        (a, b);
    }
    if(a<c) {
        swap
        (a, c);
    }
    if(b<c) {
        swap
        (b, c);
    }
    cout << "Sap xep 3 so nguyen giam dan: " << a << " " << b << " " << c << endl;
    system("pause");
    return 0;
}