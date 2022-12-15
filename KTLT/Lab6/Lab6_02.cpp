#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int m;
    ifstream inFile;
    inFile.open("BT1.txt");
    if(inFile.is_open())
    {
        inFile >> m;
        cout << "Ket qua: " << m << endl;
        cout << "Mo file thanh cong!\n";
        inFile.close();
    }else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    system("pause");
    return 0;
}