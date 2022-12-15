#include<iostream>

using namespace std;
const int MAXSIZE = 100;

void input(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void output(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i != n - 1) {
            cout << ", ";
        }else{
            cout << " \n";
        }
    }
}
bool findElement(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(x == arr[i]) {
            return true;
        }
    }
    return false;
}
void reverse(int arr[], int n) {
    for(int i = 0; i < n / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}
void delElement(int arr[], int &n, int p) {
    if(n < 1) {
        return;
    }
    if(p < 0) {
        p = 0;
    }else if(p > n) {
        p = n - 1;
    }
    for(int i = p; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
int main() {
    int arr[MAXSIZE];
    int n, x, p;
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    input(arr, n);
    cout << "\nCac phan tu trong mang: ";
    output(arr, n);
    cout << "------------------------------\n";
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    if(findElement(arr, n, x)) {
        cout << "Tim thay gia tri trong mang\n";
    }else{
        cout << "Khong tim thay gia tri trong mang\n";
    }
    reverse(arr, n);
    cout << "\nMang sau khi dao nguoc: ";
    output(arr, n);
    cout << "\nNhap vi tri cua phan tu can xoa: ";
    cin >> p;
    delElement(arr, n, p);
    cout << "Mang sau khi xoa: ";
    output(arr, n);
    system("pause");
    return 0;
}