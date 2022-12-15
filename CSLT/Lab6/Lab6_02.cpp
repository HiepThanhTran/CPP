#include<iostream>

using namespace std;

int maxOf2Value(int a, int b) {
    if(a>b) {
        return a;
    }
    return b;
}
int maxOf3Value(int a, int b, int c) {
    int max = a;
    if(b>max) {
        max = b;
    }
    if(c>max) {
        max = c;
    }
    return max;
}
int main()
{
    int a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    int max1 = maxOf2Value(a, b);
    int max2 = maxOf3Value(a, b, c);
    cout << "So lon nhat giua a va b la " << max1 << endl;
    cout << "So lon nhat giua a, b, va c la " << max2 << endl;
    system("pause");
    return 0;
}