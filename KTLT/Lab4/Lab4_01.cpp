#include <iostream>
#include <cstring>
using namespace std;

void upper(char *p, int n)
{
    if (islower(p[0]))
        p[0] -= 32;
    for (int i = 1; i < n; i++)
    {
        if (isspace(p[i - 1]))
        {
            if (islower(p[i]))
                p[i] -= 32;
        }
        else
        {
            if (isupper(p[i]))
                p[i] += 32;
        }
    }
}
int main()
{
    char a[256], b[256], *p1, *p2;
    p1 = a, p2 = b;
    cout << "Nhap chuoi thu 1: ";
    cin.get(p1, 256);
    int n1 = strlen(p1);
    cin.ignore(1);
    cout << "Nhap chuoi thu 2: ";
    cin.get(p2, 256);
    int n2 = strlen(p2);
    if (strcmp(p1, p2) == 0)
    {
        cout << "Chuoi 1 va chuoi 2 bang nhau\n";
    }
    else if (strcmp(p1, p2) > 0)
    {
        cout << "Chuoi :" << p1 << ": dai hon chuoi :" << p2 << ":" << endl;
    }
    else
    {
        cout << "Chuoi :" << p1 << ": ngan hon chuoi :" << p2 << ":" << endl;
    }
    upper(p1, n1);
    cout << "Chuoi 1 sau khi chuyen doi: " << p1 << endl;
    upper(p2, n2);
    cout << "Chuoi 2 sau khi chuyen doi: " << p2 << endl;
    strcat(p1, p2);
    cout << "Chuoi sau khi noi s2 vao s1: " << p1 << endl;
    return 0;
}