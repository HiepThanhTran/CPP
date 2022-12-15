#include<iostream>

using namespace std;
const int MAXSIZE = 100;

void input(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu arr[" << i << "] = ";
        cin >> arr[i];
    }
}
int main() {
    int arr[MAXSIZE];
    int n;
    cout << "Nhap so phan tu hien co: ";
    cin >> n;
    cout << "------------------------------\n";
    input(arr, n);
    int max = arr[0], LTN = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            LTN = i;
        }
    }
    cout << "------------------------------\n";
    cout << "Phan tu lon nhat trong mang la arr[" << LTN << "] co gia tri: " << max << endl;
    system("pause");
    return 0;
}