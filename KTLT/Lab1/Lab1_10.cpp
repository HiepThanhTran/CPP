#include<iostream>
using namespace std;

int main() {
    int a[10][10];
    int n;
    do{
        cout << "Nhap bac cua ma tran vuong: ";
        cin >> n;
        if(n < 2) cout << "Bac cua ma tran qua thap!\n";
        if(n > 10) cout << "Bac cua ma tran qua cao!\n";
    }while(n < 2 || n > 10);
    int value = 1;
    int minr, minc, maxr, maxc;
    minr = minc = 0;
    maxr = maxc = n - 1;
    while(value <= n * n)
    {
        for(int i = minc; i <= maxc; i++)
            a[minr][i] = value++;
        minr++;

        for(int i = minr; i <= maxr; i++)
            a[i][maxc] = value++;
        maxc--;

        for(int i = maxc; i >= minc; i--)
            a[maxr][i] = value++;
        maxr--;

        for(int i = maxr; i >= minr; i--)
            a[i][minc] = value++;
        minc++;
    }
    cout << "Ma tran xoan oc:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n\n";
    }
    return 0;
}