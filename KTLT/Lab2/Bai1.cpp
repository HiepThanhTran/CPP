#include<iostream>
using namespace std;

long long S(int n) {
    if(n == 1) return 1;
    return n*n + S(n - 1);
}
int main() {
    int n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
    }while(n < 1);
    cout << "Tong binh phuong tu 1 den " << n << " = " << S(n) << endl;
    return 0;
}