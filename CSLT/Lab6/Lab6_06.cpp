#include<iostream>

using namespace std;

int reverse(int n) {
    int reverse = 0;
    while(n!=0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}
int main()
{
    int n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n<1) cout << "Khong hop le!\n";
    }while(n<1);
    cout << "So dao nguoc cua " << n << " la " << reverse(n) << endl;
    system("pause");
    return 0;
}