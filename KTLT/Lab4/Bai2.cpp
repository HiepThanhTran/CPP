#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char a[51];
    cout << "Nhap vao 1 chuoi toi da 50 ky tu: ";
    cin.get(a, 51);
    int n = strlen(a);
    if(islower(a[0])) a[0] -= 32;
    for(int i = 1; i < n; i++) {
        if(isspace(a[i - 1])) {
            if(islower(a[i])) a[i] -= 32;
        }else{
            if(isupper(a[i])) a[i] += 32;
        }
    }
    cout << a << endl;
    return 0;
}