#include<iostream>
using namespace std;

long long decToBin(int n) {
    if(n / 2 == 0) return n % 2;
    return decToBin(n / 2) * 10 + n % 2;
}
long long khuDeQuy(int n) {
    int bin = 0, p = 1;
    while(n != 0) {
        bin += (n % 2) * p;
        p *= 10;
        n /= 2;
    }
    return bin;
}
int main() {
    int n;
    do{
        cout << "Nhap mot so nguyen duong: ";
        cin >> n;
    }while(n < 1);
    cout << "He so 2 cua so thap phan vua nhap la: " << decToBin(n) << endl;
    cout << "He so 2 cua so thap phan vua nhap la: " << khuDeQuy(n) << endl;
    return 0;
}