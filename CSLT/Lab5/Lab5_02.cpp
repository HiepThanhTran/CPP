#include <iostream>

using namespace std;

int main()
{
    int m, n;
    int sum = 0;
    do {
        cout << "Nhap so luong so: "; 
        cin >> m;
        if(m<1) cout << "Nhap sai. Xin nhap lai!\n";
    }while(m<1);

    for (int i = 1; i <= m; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> n;
        sum += n;
    }
    cout << "Tong " << m << " so vua nhap la " << sum << endl;
    return 0;
}
