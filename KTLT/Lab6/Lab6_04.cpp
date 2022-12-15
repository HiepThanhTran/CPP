#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("BT4.txt", ios::app);
    char s[21];
    char *p = s;
    cout << "Nhap vao 1 chuoi: ";
    cin.get(p, 21);
    if (outFile.is_open())
    {
        while (*p)
        {
            outFile << char(toupper(*p)) << endl;
            p++;
        }
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