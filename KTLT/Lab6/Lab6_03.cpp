#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    int a, b, c;
    int a1, b1, c1;
    cout << "Nhap vao 3 so nguyen: ";
    cin >> a >> b >> c;
    outFile.open("BT3.txt");
    if(outFile.is_open())
    {
        outFile << a << "#" << b << "#" << c << endl;
        cout << "Ghi file thanh cong!\n";
        outFile.close();
    }else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    inFile.open("BT3.txt");
    if(inFile.is_open())
    {
        inFile >> a1;
        inFile.ignore(1);
        inFile >> b1;
        inFile.ignore(1);
        inFile >> c1;
        cout << "Trung binh cong cua 3 so nguyen la " << double((a1 + b1 + c1)) / 3 << endl;
        cout << "Doc file thanh cong\n";
        inFile.close();
    }else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    system("pause");
    return 0;
}