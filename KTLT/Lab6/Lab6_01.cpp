#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("BT1.txt");
    int a, b, sum = 0;
    cout << "Nhap a va b: ";
    cin >> a >> b;
    sum = a + b;
    if (outFile.is_open())
    {
        outFile << sum;
        outFile.close();
        cout << "Ghi file thanh cong!\n";
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    system("pause");
    return 0;
}