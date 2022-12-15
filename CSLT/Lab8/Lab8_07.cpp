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
int min(int arr[], int n) {
    int min = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}
int location(int arr[], int n) {
    int location = 0;
    for(int i = 0; i < n; i++) {
        if(min(arr, n) == arr[i]) {
            location = i;
            break;
        }
    }
    return location;
}
int main() {
    int arr[MAXSIZE];
    int n;
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    input(arr, n);
    cout << "\nCac phan tu trong mang: ";
    output(arr, n);
    cout << "\n------------------------------\n";
    cout << "Vi tri xuat hien dau tien cua phan tu nho nhat: arr[" << location(arr, n) << "]\n";
    system("pause");
    return 0;
}