#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

bool kiemTraNam(int year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 == 1));
}
int kiemTraThang(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (kiemTraNam(year))
            return 29;
        return 28;
    }
}
bool kiemTraChuoi(char *p)
{
    int n = strlen(p);
    for (int i = 0; i < n; i++)
    {
        if (p[i] < '0' || p[i] > '9')
            return false;
    }
    return true;
}
int demNgay(int day, int month, int year)
{
    int count = day;
    for (int i = 1; i < month; i++)
    {
        count += kiemTraThang(i, year);
    }
    return count;
}
int main()
{
    char *day, *month, *year;
    char s1[11], tmp[11], *p1;
    char s2[] = "-", *p2;
    p1 = s1, p2 = s2;
    int len1, len2, len3;
    do
    {
        do
        {
            system("cls");
            cout << "Nhap vao 1 chuoi co dang ngay-thang-nam: ";
            cin >> p1;
            strcpy_s(tmp, p1);
            day = strtok(tmp, p2);
            len1 = strlen(day);
            month = strtok(NULL, p2);
            len2 = strlen(month);
            year = strtok(NULL, p2);
            len3 = strlen(year);
            if (!kiemTraChuoi(day) || !kiemTraChuoi(month) || !kiemTraChuoi(year) || !(len1 == 2) || !(len2 == 2) || !(len3 == 4))
            {
                cout << "\nKhong dung dinh dang Ngay-thang-nam. Nhap lai!\n\n";
                getch();
            }
        } while (!kiemTraChuoi(day) || !kiemTraChuoi(month) || !kiemTraChuoi(year) || !(len1 == 2) || !(len2 == 2) || !(len3 == 4));
        if (atoi(day) < 1 || atoi(day) > kiemTraThang(atoi(month), atoi(year)) || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1)
        {
            cout << "\nNgay-thang-nam khong hop le. Nhap lai!\n\n";
            getch();
        }
    } while (atoi(day) < 1 || atoi(day) > kiemTraThang(atoi(month), atoi(year)) || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1);
    cout << p1 << " la ngay thu " << demNgay(atoi(day), atoi(month), atoi(year)) << " trong nam\n";
    getch();
    return 0;
}