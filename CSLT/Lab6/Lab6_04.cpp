#include<iostream>

using namespace std;

int Tong(int n) {
    int sum = 0;
    for(int i=1; i<=n; i++) {
        sum += i;
    }
    return sum;
}
long long giaiThua(int n) {
    long long giaiThua = 1;
    for(int i=1; i<=n; i++) {
        giaiThua *= i;
    }
    return giaiThua;
}
int main()
{
    int n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n<1) cout << "Khong hop le!\n";
    }while(n<1);
    cout << "Tong cac so tu 1 den " << n << " = " << Tong(n) << endl;
    cout << "Ket qua " << n << "! = " << giaiThua(n) << endl; 
    system("pause");
    return 0;
}