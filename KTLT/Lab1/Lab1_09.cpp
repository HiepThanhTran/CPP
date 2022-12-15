#include<iostream>
using namespace std;

int main() {
    int a[10][10];
    int n;
    do{
        cout << "Nhap bac cua ma tran vuong: ";
        cin >> n;
    }while(n < 2 || n > 10);
    int value = 1;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < n; j++) {
                a[j][i] = value++;
            }
        }else{
            for(int j = n - 1; j >= 0; j--) {
                a[j][i] = value++;
            }
        }
    }
    cout << "Mang theo zigzac cot:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
    return 0;
}