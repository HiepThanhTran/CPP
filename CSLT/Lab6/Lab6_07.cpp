#include<iostream>
#include<math.h>

using namespace std;

bool soNguyenTo(int n) {
    if(n<2) {
        return false;
    }else{
        for(int i=2; i<=sqrt(n); i++) {
            if(n % i == 0) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n<1) cout << "Khong hop le!\n";
    }while(n<1);
    if(soNguyenTo(n) == true) {
        cout << n << " la so nguyen to\n";
    }else{
        cout << n << " khong phai so nguyen to\n";
    }
    system("pause");
    return 0;
}