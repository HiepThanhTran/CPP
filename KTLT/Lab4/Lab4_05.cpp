#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

int main()
{
    char password[11];
    int soLanDN = 3;
    for (int i = 0; i < soLanDN; i++)
    {
        bool flag = false;
        int k = 0;
        cout << "Nhap mat khau: ";
        while ((password[k] = _getch()) != 13 && ++k < 11)
            cout << "X";
        password[k] = '\0';
        if (!strcmp(password, "SinhVienCQ"))
        {
            cout << "\nDang nhap thanh cong\n";
            flag = true;
        }
        else
            cout << "\nDang nhap that bai\n";
        if (flag) break;
    }
    return 0;
}