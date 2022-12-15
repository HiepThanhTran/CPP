#include<iostream>
using namespace std;

int main() {
    char a[51];
    cout << "Nhap vao 1 chuoi toi da 50 ky tu: ";
    cin.get(a, 51);
    char *s = a;
    int demChu = 0, demSo = 0, demKC = 0;
    while(*s != '\0') {
        if(isalpha(*s)) demChu++;
        if(isdigit(*s)) demSo++;
        if(isspace(*s)) demKC++;
        s++; 
    }
    cout << "Co " << demChu << " chu\n";
    cout << "Co " << demSo << " so\n";
    cout << "Co " << demKC << " khoang trang\n";
    return 0;
}