#include<iostream>
using namespace std;

long long S4(int n) {
    if(n == 1) return 1;
    return n * S4(n - 1);
}
int main() {
    int n;
    do{
        cout << "Nhap n: ";
        cin >> n;
    }while(n < 1);
    cout << n << "! = " << S4(n) << endl;
    return 0;
}