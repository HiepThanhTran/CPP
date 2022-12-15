#include<iostream>

using namespace std;

int UCLN(int m, int n) {
    int r = 0;
    while(n != 0) {
        r = n;
        n = m % n;
        m = r;
    }
    return m;
}
int main()
{
    int m, n;
    do{
        cout << "Nhap m: ";
        cin >> m;
        cout << "Nhap n: ";
        cin >> n;
        if(m<0 || n<0) cout << "Khong hop le. Xin nhap lai!!\n";
    }while(m<0 || n<0);
    cout << "Uoc chung lon nhat cua " << m << " va " << n << " la " << UCLN(m, n) << endl;
    system("pause");
    return 0;
}