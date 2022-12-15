#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char hTen[256], *p;
    char tmp[] = ", ";
    p = hTen;
    cout << "Nhap vao ho, ten: ";
    cin.get(p, 256);
    char *ptok = strtok(p, tmp);
    while (ptok != NULL)
    {
        cout << ptok << " ";
        ptok = strtok(NULL, tmp);
    }
    return 0;
}