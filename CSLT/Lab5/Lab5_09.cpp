#include<iostream>

using namespace std;

int main()
{
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if(n<1) cout << "Khong hop le!\n";
    }while(n<1);

    for(int i=1; i<=10; i++) {
        cout << n << " x " << i << " = " << n*i << endl;
    }
    return 0;
}