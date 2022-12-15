#include<iostream>
#include<math.h>

using namespace std;
const int MAXSIZE = 100;

void input(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu arr[" << i << "] = ";
        cin >> a[i];
    }
}
void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
}
void delElements(int a[], int &n, int x) {
    for(int i = x; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
}
void delDuplicates(int a[], int &n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                delElements(a, n, j);
                j--;
            }
        }
    }
}
int main() {
    int a[MAXSIZE];
    int n;
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    input(a, n);
    cout << "\nCac phan tu trong mang: ";
    output(a, n);
    cout << "\n------------------------------\n";
    cout << "Mang sau khi xoa cac phan tu trung nhau: ";
    delDuplicates(a, n);
    output(a, n);
    cout << "\n";
    system("pause");
    return 0;
}