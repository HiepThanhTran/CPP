#include<iostream>

using namespace std;

bool soHoanThien(int n) {
    int sum = 0;
    if(n<6) {
        return false;
    }
    for(int i=1; i<n; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    if(sum == n) {
        return true;
    }
    return false;
}
int main()
{
    int n; //6, 28, 496, 8128
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if(soHoanThien(n) == true) {
        cout << n << " la so hoan thien\n";
    }else{
        cout << n << " khong phai so hoan thien\n";
    }
    system("pause");
    return 0;
}