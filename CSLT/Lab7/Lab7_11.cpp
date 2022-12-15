#include<iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a, b;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;
    if(a<b) {
        swap(a, b);
        cout << "\nSap xep giam dan: " << a << " " << b << endl;
    }else{
        cout << "\nSap xep giam dan: " << a << " " << b << endl;
    }
    system("pause");
    return 0;
}