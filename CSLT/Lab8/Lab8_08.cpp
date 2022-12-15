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
        cout << arr[i] << "  ";
    }
}
int count(int arr[], int n, int x) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(x == arr[i]) count++;
    }
    return count;
}
int main() {
    int arr[MAXSIZE];
    int n, x;
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    input(arr, n);
    cout << "\nCac phan tu trong mang: ";
    output(arr, n);
    cout << "\n------------------------------\n";
    cout << "Nhap gia tri can kiem tra: ";
    cin >> x;
    cout << "So lan gia tri " << x << " xuat hien trong mang la " << count(arr, n, x) << endl;
    system("pause");
    return 0;
}