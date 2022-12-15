#include<iostream>

using namespace std;
const int MAX = 1000;

int main() {
    int N;
    do{
        cout << "Nhap so nguyen N: ";
        cin >> N;
        if(N < 2) cout << "Vui long nhap N >= 2\n";
    }while(N < 2);
    bool arr[MAX];
    for(int i = 2; i <= N; i++) {
        arr[i] = true;
    }
    for(int i = 2; i <= N; i++) {
        if(arr[i] == true) {
            for(int j = 2 * i; j <= N; j += i) {
                arr[j] = false;
            }
        }
    }
    cout << "\nCac so nguyen to tu 2 den " << N << ":\n";
    for(int i = 2; i <= N; i++) {
        if(arr[i] == true) {
            cout << i << "  ";
        }
    }
    cout << "\n";
    system("pause");
    return 0;
}