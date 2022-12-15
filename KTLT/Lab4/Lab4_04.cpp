#include <iostream>
#include <cstring>
using namespace std;

char chuyenKTThuong(char kt)
{
    if (kt >= 'A' && kt <= 'Z')
        return kt + 32;
    return kt;
}
bool palindrome(char *p)
{
    int n = strlen(p);
    for (int i = 0; i < n / 2; i++)
        if (chuyenKTThuong(p[i]) != chuyenKTThuong(p[n - 1 - i]))
            return false;
    return true;
}
int main()
{
    char s[256], *p;
    p = s;
    cout << "Nhap 1 chuoi ki tu (Khong chua khoang trang): ";
    cin >> p;
    if (palindrome(p))
    {
        cout << "La chuoi Palindrome\n";
    }
    else
    {
        cout << "Khong phai chuoi Palindrome\n";
    }
    return 0;
}