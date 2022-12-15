#include <iostream>

using namespace std;

int UCLN(int m, int n)
{
    int r = 0;
    while (n != 0)
    {
        r = n;
        n = m % n;
        m = r;
    }
    return m;
}
int main()
{
    int m, n, ucln = 0; //m là tử, n là mẫu
    cout << "Nhap tu so: ";
    cin >> m;
    cout << "Nhap mau so: ";
    cin >> n;
    ucln = abs(UCLN(m, n));
    if (n == 0){
        cout << "INVALID\n";
    }else if (m % n == 0){
        cout << "Phan so toi gian: " << m / n << endl;
    }else if (n < 0){
        m = m / (-1 * ucln);
        n = n / (-1 * ucln);
        cout << "Phan so toi gian: " << m << "/" << n << endl;
    }else{
        m = m / ucln;
        n = n / ucln;
        cout << "Phan so toi gian: " << m << "/" << n << endl;
    }
    system("pause");
    return 0;
}