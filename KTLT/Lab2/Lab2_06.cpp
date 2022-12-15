#include<iostream>
using namespace std;

int soDaoNguoc(int n, int sdn = 0) {
    if(n == 0) return sdn;
    return soDaoNguoc(n/10, (sdn * 10) + (n % 10));
}
int main() {
    int n;
    do{
        cout << "Nhap mot so nguyen khong am: ";
        cin >> n;
    }while(n < 1);
    cout << "So dao nguoc cua " << n << " la: " << soDaoNguoc(n) << endl;
    return 0;
}