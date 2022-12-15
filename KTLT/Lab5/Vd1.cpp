#include <iostream>
using namespace std;
const int MAXSIZE = 50;

struct intArr
{
    int arr[MAXSIZE];
    int n;
};

void nhapArr(intArr &a)
{
    do
    {
        cout << "Nhap so luong phan tu cua mang: ";
        cin >> a.n;
    } while (a.n < 0 || a.n > MAXSIZE);
    cout << "Nhap " << a.n << " gia tri cho mang: ";
    for (int i = 0; i < a.n; i++)
    {
        cin >> a.arr[i];
    }
}
void xuatArr(intArr a)
{
    for (int i = 0; i < a.n; i++)
    {
        cout << a.arr[i] << " ";
    }
    cout << "\n";
}
int sumOfEle(intArr a)
{
    int sum = 0;
    for (int i = 0; i < a.n; i++)
    {
        sum += a.arr[i];
    }
    return sum;
}
int main()
{
    intArr a;
    nhapArr(a);
    cout << "Mang vua nhap: ";
    xuatArr(a);
    cout << "\n- Tong cac phan tu trong mang: " << sumOfEle(a) << endl;
    system("pause");
    return 0;
}