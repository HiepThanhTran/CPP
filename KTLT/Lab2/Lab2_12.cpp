#include<iostream>
using namespace std;
const int maxSZ = 50;

void nhapMang(int a[], int na) {
    cout << "\n";
    for(int i = 0; i < na; i++) {
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "\n";
}
void xuatMang(int a[], int na) {
    for(int i = 0; i < na; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int min(int a[], int na) {
    if(na == 1) return a[0];
    if(a[na - 1] < min(a, na - 1)) return a[na - 1];
    return min(a, na - 1);
}
int main() {
    int a[maxSZ], na;
    do{
        cout << "Nhap so luong phan tu mang a: ";
        cin >> na;
        if(na < 1 || na > maxSZ) cout << "Khong hop le!\n";
    }while(na < 1 || na > maxSZ);
    nhapMang(a, na);
    cout << "Mang vua nhap: ";
    xuatMang(a, na);
    cout << "Phan tu nho nhat trong mang a: " << min(a, na) << endl;
    return 0;
}