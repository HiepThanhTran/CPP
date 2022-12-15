#include<iostream>

using namespace std;
const int MAXSIZE = 100;

void input(int arr[], int &n) {
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    for(int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void output(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
}
void del(int arr[], int &n, int p) {
    if(n < 1) {
        return;
    }
    if(p < 0) {
        p = 0;
    }else if(p > n) {
        p = n - 1;
    }
    for(int i = p; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
int main() {
    int arr[MAXSIZE];
    int n, p;
    input(arr, n);
    cout << "------------------------------\n";
    cout << "Mang truoc khi xoa: ";
    output(arr,n);
    cout << "\nNhap vi tri cua phan tu can xoa: ";
    cin >> p;
    del(arr, n, p);
    cout << "Mang sau khi xoa: ";
    output(arr, n);
    cout << "\n";
    system("pause");
    return 0;
}