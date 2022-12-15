#include<iostream>
using namespace std;

int main() {
    int x, y;
    int *p;
    p = &x;
    *p = 80;
    cout << "Dia chi cua bien x: " << (int)&x << endl;
    cout << "Gia tri cua con tro p tro den: " << *p << endl;
    cout << "Gia tri cua bien x: " << x << endl;
    if(x == *p) {
        cout << "Gia tri x la gia tri con tro p luu tru\n";
    }else{
        cout << "Gia tri x khong phai la gia tri con p luu tru\n";
    }
    return 0;
}