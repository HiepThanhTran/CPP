#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void nhapChuoi(string &s)
{
    cout << "Nhap vao 1 chuoi: ";
    getline(cin, s);
}
void ghiFile(string s)
{
    ofstream outFile;
    outFile.open("BT9.txt");
    if (outFile.is_open())
    {
        outFile << s;
        cout << "Ghi file thanh cong!\n";
        outFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
}
void docFile(string &s)
{
    ifstream inFile;
    inFile.open("BT9.txt");
    if (inFile.is_open())
    {
        getline(inFile, s);
        cout << "Doc file thanh cong!\n";
        inFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
}
int count(string s)
{
    int count = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i' ||
            s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I')
            count++;
    }
    return count;
}
int countOfFile(string s)
{
    ifstream inFile;
    inFile.open("BT9.txt");
    char kt;
    int count = 0;
    if (inFile.is_open())
    {
        while (inFile >> kt)
        {
            if (kt == 'u' || kt == 'e' || kt == 'o' || kt == 'a' || kt == 'i' ||
                kt == 'U' || kt == 'E' || kt == 'O' || kt == 'A' || kt == 'I')
                count++;
        }
        cout << "Doc file thanh cong!\n";
        inFile.close();
    }
    else
    {
        cout << "Mo file khong thanh cong!\n";
    }
    return count;
}
int main()
{
    string s1, s2, tmp1, tmp2;
    nhapChuoi(s1);
    nhapChuoi(s2);
    ghiFile(s1);
    docFile(tmp1);
    cout << "Chuoi doc tu file la " << tmp1 << endl;
    if (s1 == s2)
        cout << "Hai chuoi bang nhau\n";
    else
        cout << "Hai chuoi khong bang nhau\n";
    tmp2 = s1 + s2;
    cout << "Chuoi sau khi noi s2 vao s1 la " << tmp2 << endl;
    cout << "Chuoi s1 [" << s1 << "] co " << count(s1) << " nguyen am\n";
    cout << "Chuoi s1 [" << s2 << "] co " << count(s2) << " nguyen am\n";
    cout << "Chuoi dang luu trong file [" << tmp1 << "] co " << countOfFile(tmp1) << " nguyen am\n";
    system("pause");
    return 0;
}