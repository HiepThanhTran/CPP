#include <iostream>
#include <fstream>
using namespace std;

void ghiFile(int a, int b, int c)
{
    ofstream outFile;
    outFile.open("BT8.txt");
    if (outFile.is_open())
    {
        outFile << a << "-" << b << "-" << c << endl;
        cout << "Ghi file thanh cong!\n";
        outFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
}
void docFile(int &a, int &b, int &c)
{
    ifstream inFile;
    inFile.open("BT8.txt");
    if (inFile.is_open())
    {
        inFile >> a;
        inFile.ignore(1);
        inFile >> b;
        inFile.ignore(1);
        inFile >> c;
        cout << "Doc file thanh cong!\n";
        inFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
}
int main()
{
    int a, b, c;
    cout << "Nhap vao 3 so nguyen: ";
    cin >> a >> b >> c;
    ghiFile(a, b, c);
    int a1, b1, c1;
    docFile(a1, b1, c1);
    cout << a1 << " " << b1 << " " << c1 << endl;
    system("pause");
    return 0;
}