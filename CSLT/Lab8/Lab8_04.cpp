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
int sumOfElements(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
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
    cout << "Tong cac phan tu = " << sumOfElements(arr, n) << endl;
    cout << "Gia tri trung binh cua cac phan tu = " << (sumOfElements(arr, n)) / n << endl;
    system("pause");
    return 0;
}