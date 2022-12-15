#include<iostream>

using namespace std;

int main()
{
    int n1, n2, soLe = 0, soChan = 0, demuoc = 0;
    do {
        cout << "Nhap so nguyen duong n1: ";
        cin >> n1;
        cout << "Nhap so nguyen duong n2: ";
        cin >> n2;
        if(n1>n2 || n1<1) cout << "Khong hop le. n1 < n2. Xin nhap lai!\n";
    }while(n1>n2 || n1<1);

    for(int i=n1; i<=n2; i++) {
        if(i % 2 == 0) {
            soChan++;
        }else{
            soLe++;
        }
        if(10 % i == 0) demuoc++;
    }
    cout << "Co " << soLe << " so le" << endl;
    cout << "Co " << soChan << " so chan" << endl;
    cout << "Co " << demuoc << " so la uoc cua 10" << endl;
    return 0;
}