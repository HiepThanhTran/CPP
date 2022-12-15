#include<iostream>
using namespace std;

void taoTamGiacPascal(int **p, int h) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                p[i][j] = 1;
            }else{
                p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
            }
        }
    }
}
void xuatTamGiacPascal(int **p, int h) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j <= i; j++) {
            cout << " " << p[i][j] << "\t";
        }
        cout << "\n\n";
    }
}
int main() {
    int h;
    do{
        cout << "Nhap ma tran vuong cap h (h > 0): ";
        cin >> h;
    }while(h < 1);
    int **p;
    p = new int *[h];
    for(int i = 0; i < h; i++) {
        p[i] = new int[h];
    }
    taoTamGiacPascal(p, h);
    cout << "\nTam giac Pascal:\n";
    xuatTamGiacPascal(p, h);
    for(int i = 0; i < h; i++) {
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
    return 0;
}