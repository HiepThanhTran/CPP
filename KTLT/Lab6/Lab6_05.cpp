#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    int count = 0;
    char kt[2];
    inFile.open("BT4.txt");
    if (inFile.is_open())
    {
        while (inFile.getline(kt, 2))
            count++;
        cout << "Trong file co " << count << " ky tu\n";
        cout << "Doc file thanh cong!\n";
        inFile.close();
    }
    else
        cout << "Mo file khong thanh cong!\n";
    system("pause");
    return 0;
}