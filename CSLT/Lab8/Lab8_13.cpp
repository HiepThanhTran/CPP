#include<iostream>

using namespace std;
const int MAXSIZE = 100;

void input(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Phan tu arr[" << i << "] = ";
        cin >> a[i];
    }
}
void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
}
void ptuPbiet(int a[], int b[], int n, int &m) {
    b[0] = a[0], m = 1;
    for(int i = 1; i < n; i++) {
        bool kiemtra = true;
        for(int j = i - 1; j >= 0; j--) {
            if(a[i] == a[j]) {
                kiemtra = false;
                break;
            }
        }
        if(kiemtra == true) {
            b[m] = a[i];
            m++;
        }
    }
    cout << "Cac phan tu phan biet: ";
    output(b, m);
}
void count(int a[], int b[], int n, int m) {
    ptuPbiet(a, b, n, m);
    cout << "\n";
    for(int i = 0; i < m; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(b[i] == a[j]) {
                count++;
            }
        }
        cout << "Gia tri " << b[i] << " xuat hien " << count << " lan\n";
    }
}
int main() {
    int a[MAXSIZE], b[MAXSIZE];
    int n, m = 0;
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    input(a, n);
    cout << "\nCac phan tu trong mang: ";
    output(a, n);
    cout << "\n------------------------------\n";
    count(a, b, n, m);
    cout << "\n";
    system("pause");
    return 0;
}