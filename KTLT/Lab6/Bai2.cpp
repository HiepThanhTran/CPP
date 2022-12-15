#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile;
    string hoTen = " ";
    int namSinh;
    inFile.open("infor.txt");
    if (inFile.is_open())
    {
        getline(inFile, hoTen, '#');
        inFile >> namSinh;
        inFile.ignore(1);
        inFile.close();
        cout << "Ho va ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
    else
    {
        cout << "Khong mo duoc file de doc du lieu\n";
    }
    return 0;
}