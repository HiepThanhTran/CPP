#include<iostream>
#include<math.h>

using namespace std;

double luyThua(double x, int y) {
    return pow(x, y);
}
int main()
{
    double x;
    int y;
    cout << "Nhap co so x: ";
    cin >> x;
    cout << "Nhap so mu y: ";
    cin >> y;
    cout << "Ket qua x^y = " << luyThua(x, y) << endl;
    system("pause");
    return 0;
}