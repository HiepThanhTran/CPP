#include<iostream>

using namespace std;

int sum(int n) {
    int sum = 0;
    while(n!=0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}
int main()
{
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    cout << "Tong cac chu so cua " << n << " la " << sum(n) << endl;
    system("pause");
    return 0;
}