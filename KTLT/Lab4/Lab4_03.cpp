#include <iostream>
#include <cstring>
using namespace std;

char *xoaKhoangTrang(char *p)
{
    // Xóa khoảng trắng đầu chuỗi
    while (isspace(p[0]))
    {
        int n = strlen(p);
        for (int i = 0; i < n; i++)
            p[i] = p[i + 1];
        p[n - 1] = '\0';
    }
    // Xóa khoảng trắng cuối chuỗi
    while (isspace(p[strlen(p) - 1]))
    {
        int n = strlen(p);
        p[n - 1] = '\0';
    }
    return p;
}
void count(char *p)
{
    int space = 0, number = 0, alpha = 0, lower = 0, upper = 0;
    while (*p)
    {
        if (isspace(*p) && !(isspace(*(p + 1))))
            space++;
        if (isdigit(*p))
            number++;
        if (isalpha(*p))
            alpha++;
        if (islower(*p))
            lower++;
        if (isupper(*p))
            upper++;
        p++;
    }
    cout << "\nChuoi co " << space << " khoang trang\n";
    cout << "Chuoi co " << number << " chu so\n";
    cout << "Chuoi co " << alpha << " chu cai\n";
    cout << "Chuoi co " << lower << " chu cai thuong\n";
    cout << "Chuoi co " << upper << " chu cai in hoa\n";
}
char *inHoa(char *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (islower(p[i]))
            p[i] -= 32;
    }
    return p;
}
char *inThuong(char *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isupper(p[i]))
            p[i] += 32;
    }
    return p;
}
char *inHoaKiTuDau(char *p, int n)
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
    return p;
}
int main()
{
    char s[256], *p;
    p = s;
    cout << "Nhap vao 1 chuoi ki tu: ";
    cin.get(p, 256);
    int n = strlen(p);
    cout << "\nChuoi ban dau [" << p << "]\n";
    xoaKhoangTrang(p);
    cout << "\nChuoi sau khi xoa khoang trang dau chuoi va cuoi chuoi [" << xoaKhoangTrang(p) << "]" << endl;
    count(p);
    cout << "\nChuoi sau khi chuyen tat ca sang in hoa [" << inHoa(p, n) << "]\n";
    cout << "\nChuoi sau khi chuyen tat ca sang chu thuong [" << inThuong(p, n) << "]\n";
    cout << "\nChuoi sau khi chuyen cac ki tu dau sang in hoa [" << inHoaKiTuDau(p, n) << "]\n";
    return 0;
}