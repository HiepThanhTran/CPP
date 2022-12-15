//Viết chương trình nhận vào 2 số nguyên dương n1 và n2 (n1 < n2).
//Đếm và xuất ra màn hình kết quả có bao nhiêu số là ước của 10 trong phạm vi từ n1 đến n2.

#include<iostream>

using namespace std;

int main()
{
    int n1, n2, dem = 0;
    do {
        cout << "Nhap n1: ";
        cin >> n1;
        cout << "Nhap n2: ";
        cin >> n2;
        if(n1 > n2)
            cout << "n1 phai nho hon n2. Xin nhap lai!\n";
    }while(n1 > n2);

    while(n1 <= n2) {
        if(10 % n1 == 0) {
            dem++;
        }
        n1++;
    }
    cout << "So uoc cua 10 la: " << dem << endl;
    return 0;
}