#include <iostream>
#include <cmath>
using namespace std;

long long binToDec(int n, int exp = 0)
{
    if (n < 10)
        return (n % 10) * pow(2, exp);
    return (n % 10) * pow(2, exp) + binToDec(n / 10, exp + 1);
}
long long khuDeQuy(int n)
{
    int dec = 0, p = 0;
    while (n != 0)
    {
        dec += (n % 10) * pow(2, p++);
        n /= 10;
    }
    return dec;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap mot so o dang nhi phan (0 va 1): ";
        cin >> n;
        if (n < 0)
            cout << "Vui long nhap so nguyen duong!\n";
    } while (n < 0);
    cout << "He so 10 cua so nhi phan vua nhap: " << binToDec(n) << endl;
    cout << "He so 10 cua so nhi phan vua nhap: " << khuDeQuy(n) << endl;
    return 0;
}