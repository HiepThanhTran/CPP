#include<iostream>
using namespace std;

long long decToBin(int n) {
    if(n / 2 == 0) return n % 2;
    return decToBin(n/2) * 10 + n % 2;
}
int main() {
    int n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
    }while(n < 1);
    cout << "He 2 cua so thap phan vua nhap la: " << decToBin(n) << endl;
    return 0;
}