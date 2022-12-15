#include<iostream>
#include<math.h>

using namespace std;
const int MAXSIZE = 100;

void input(int arr[], int a) {
    for(int i = 0; i < a; i++) {
        cout << "Nhap he so a" << i+1 << " = ";
        cin >> arr[i];
    }
}
void output(int arr[], int a) {
    for(int i = 0; i < a; i++) {
        cout << arr[i] << "  ";
    }
}
long double daThuc(int arr[], int a, int n, int x) {
    long double sum = 0;
    for(int i = 0; i < a; i++) {
        sum += arr[i] * pow(x, n - i);
    }
    return sum;
}
int main() {
    int arr[MAXSIZE];
    int a, n, x;
    cout << "\t\tDA THUC: ax^n + ax^(n-1) + ... + a\n";
    cout << "------------------------------\n";
    cout << "Nhap so luong he so cua da thuc: ";
    cin >> a;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Nhap bac cua da thuc: ";
    cin >> n;
    cout << "------------------------------\n";
    input(arr, a);
    cout << "\nCac he so cua da thuc: ";
    output(arr, a);
    cout << "\n------------------------------\n";
    cout << "Ket qua cua da thuc tren = " << daThuc(arr, a, n, x) << endl;
    system("pause");
    return 0;
}