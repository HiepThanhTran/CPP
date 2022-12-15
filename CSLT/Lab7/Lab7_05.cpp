#include<iostream>
#include<string>

using namespace std;

bool kiemTra1(char c) {
    if(c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
bool kiemTra2(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}
int main()
{
    char c;
    string str;
    int dem1 = 0, dem2 = 0;
    cout << "Nhap vao 1 ky tu: ";
    cin >> c;
    cin.ignore();
    cout << "Nhap vao chuoi ky tu: ";
    getline(cin, str);
    if(kiemTra1(c)) {
        cout << c << " la ky tu so\n";
    }else{
        cout << c << " khong phai la ky tu so\n";
    }
    if(kiemTra2(c)) {
        cout << c << " la ky tu chu cai\n";
    }else{
        cout << c << " khong phai la ky tu chu cai\n";
    }
    for(int i=0; i<=str.size(); i++) {
        if(kiemTra1(str[i])) dem1++;
        if(kiemTra2(str[i])) dem2++;
    }
    cout << "\nChuoi vua nhap: " << str << endl;
    cout << "Co " << dem1 << " ky tu so\n";
    cout << "Co " << dem2 << " ky tu chu cai\n";
    system("pause");
    return 0;
}