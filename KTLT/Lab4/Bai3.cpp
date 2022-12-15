#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char a[51];
    cout << "Nhap 1 chuoi toi da 50 ky tu: ";
    cin.get(a, 51);
    int n = strlen(a);
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}