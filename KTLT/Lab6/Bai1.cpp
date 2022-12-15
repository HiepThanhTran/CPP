#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("infor.txt");
    string hoTen = " ";
    int namSinh;
    cout << "Nhap ho va ten: ";
    getline(cin, hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    if (outFile.is_open())
    {
        outFile << hoTen << '#' << namSinh << endl;
        outFile.close();
        cout << "Ghi file thanh cong!\n";
    }
    else
    {
        cout << "Khong mo duoc file de ghi du lieu!\n";
    }
    return 0;
}