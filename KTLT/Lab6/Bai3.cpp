#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeFile(string hoTen, int namSinh)
{
    ofstream outFile;
    outFile.open("infor.txt");
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
}
void readFile(string &hoTen, int &namSinh)
{
    ifstream inFile;
    inFile.open("infor.txt");
    if (inFile.is_open())
    {
        getline(inFile, hoTen, '#');
        inFile >> namSinh;
        inFile.close();
    }
    else
    {
        cout << "Khong mo duoc file de doc du lieu!\n";
    }
}
int main()
{
    string hoTen = " ";
    int namSinh;
    cout << "Nhap ho va ten: ";
    getline(cin, hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    string hoTen1;
    int namSinh1;
    writeFile(hoTen, namSinh);
    readFile(hoTen1, namSinh1);
    cout << "Ho va ten: " << hoTen1 << endl;
    cout << "Nam sinh: " << namSinh1 << endl;
    return 0;
}