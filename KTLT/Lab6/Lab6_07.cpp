#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double luong;
    ofstream outFile;
    outFile.open("BT7.txt", ios::app);
    if (outFile.is_open())
    {
        cout << "Nhap vao he so luong cua nhan vien (Nhap -1 de ket thuc):\n";
        do
        {
            cin >> luong;
            if(luong != -1)
                outFile << luong << endl;
        } while (luong != -1);
        cout << "Ghi file thanh cong!\n";
        outFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    system("pause");
    return 0;
}