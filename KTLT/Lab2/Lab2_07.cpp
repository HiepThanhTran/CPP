#include<iostream>
using namespace std;

int tongChan(int n, int sum = 0) {
    if(n == 0) return sum;
    if((n % 10) % 2 == 0) return tongChan(n/10, sum + (n % 10));
    return tongChan(n/10, sum);
}
int tongLe(int n, int sum = 0) {
    if(n == 0) return sum;
    if((n % 10) % 2 != 0) return tongLe(n/10, sum + (n % 10));
    return tongLe(n/10, sum);
}
int main() {
    int n;
    do{
        cout << "Nhap mot so nguyen khong am: ";
        cin >> n;
    }while(n < 1);
    cout << "Tong cac chu so chan cua " << n << " = " << tongChan(n) << endl;
    cout << "Tong cac chu so le cua " << n << " = " << tongLe(n) << endl;
    return 0;
}