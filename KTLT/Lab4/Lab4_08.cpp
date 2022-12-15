#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char hoTen[256];
    cout << "Nhap ho va ten: ";
    cin.get(hoTen, 256);
    char* p = hoTen;
    char* temp = p;
    cout << "Ho: ";
    while (*temp != ' ')
    {
        cout << *temp;
        temp++;
    }
    char* q = p + strlen(p) - 1;
    while (*q != ' ')
        q--;
    cout << "\nChu lot: ";
    for (int i = temp - p + 1; i < q - p; i++)
        cout << p[i];
    cout << "\nTen: ";
    while (*q)
    {
        if (*q == ' ') q++;
        cout << *q;
        q++;
    }
    return 0;
}