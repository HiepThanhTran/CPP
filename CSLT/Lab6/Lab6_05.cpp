#include<iostream>

using namespace std;

void veHinhVuong(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << " * ";
        }
        cout << endl;
    }
}
int main()
{
    double n;
    do{
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if(n<1) cout << "Khong hop le\n";
    }while(n<1);
    veHinhVuong(n);
    system("pause");
    return 0;
}