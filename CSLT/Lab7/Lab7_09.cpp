#include<iostream>

using namespace std;

int Fibonacci(int n) {
    int so1 = 0, so2 = 1, soF = 0;
    if(n==1 || n==2) {
        return 1;
    }
    for(int i=3; i<=n; i++) {
        soF = so1 + so2;
        so1 = so2;
        so2 = soF;
    }
    return soF;
}
int main()
{
    int n;
    do{
        cout << "Nhap n: ";
        cin >> n;
        if(n < 1) cout << "Khong hop le!!\n";
    }while(n < 1);
    cout << "So Fibonacci thu " << n << " la " << Fibonacci(n) << endl;
    system("pause");
    return 0;
}