#include<iostream>
#include<string>

using namespace std;

bool kiemTra1(char n) {
    return (n >= 'A' && n <= 'Z');
}
bool kiemTra2(char n) {
    return (n >= 'a' && n <= 'z');
}
int main()
{
    char n;
    string str;
    int dem1 = 0, dem2 = 0;
    cout << "Nhap vao 1 ky tu: ";
    cin >> n;
    cin.ignore();
    cout << "Nhap vao chuoi ky tu: ";
    cin >> str;
    if(kiemTra1(n)) {
        cout << n << " la chu in hoa.\n";
    }
    if(kiemTra2(n)) {
        cout << n << " la chu in thuong.\n";
    }
    for(int i=0; i<=str.size(); i++) {
        if(kiemTra1(str[i])) dem1++;
        if(kiemTra2(str[i])) dem2++;
    }
    cout << "Chuoi " << str << " co " << dem1 << " chu in hoa.\n";
    cout << "Chuoi " << str << " co " << dem2 << " chu in thuong.\n";
    system("pause");
    return 0;
}