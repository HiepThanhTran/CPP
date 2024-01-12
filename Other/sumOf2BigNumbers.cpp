#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    while (s1.length() < s2.length())
        s1 = '0' + s1;
    while (s2.length() < s1.length())
        s2 = '0' + s2;
    int sum = 0, nho = 0;
    int size = s1.length();
    string result;
    for (int i = size - 1; i >= 0; i--)
    {
        sum = (s1[i] - 48) + (s2[i] - 48) + nho;
        result += sum % 10 + 48;
        nho = sum / 10;
    }
    if (nho != 0)
        result += (nho + 48);
    int sizekq = result.length();
    for (int i = sizekq - 1; i >= 0; i--)
        cout << result[i];
    getch();
    return 0;
}