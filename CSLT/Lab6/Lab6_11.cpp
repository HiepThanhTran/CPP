#include<iostream>

using namespace std;

int soDoiXung(int n) {
    int sdn = 0;
    int temp = n;
    while(n!=0) {
        sdn = sdn * 10 + n % 10;
        n /= 10;
    }
    if(sdn == temp) {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    if(soDoiXung(n) == 1) {
        cout << n << " la so doi xung\n";
    }else{
        cout << n << " khong phai so doi xung\n";
    }
    system("pause");
    return 0;
}