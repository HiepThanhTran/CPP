#include<iostream>

using namespace std;
const int MAXSIZE = 100;

void input(double values[], int currentSize) {
    for(int i = 0; i < currentSize; i++) {
        cout << "Nhap gia tri phan tu v[" << i << "] = ";
        cin >> values[i];
    }
}
void output(double values[], int currentSize) {
    for(int i = 0; i < currentSize; i++) {
        cout << values[i];
        if(i != currentSize - 1) {
            cout << ", ";
        }else{
            cout << "  ";
        }
    }
}
int main() {
    double values[MAXSIZE];
    int currentSize;
    cout << "Nhap so phan tu hien co: ";
    cin >> currentSize;
    cout << "------------------------------\n";
    input(values, currentSize);
    cout << "\nCac phan tu trong mang: ";
    output(values, currentSize);
    cout << "\n";
    system("pause");
    return 0;
}