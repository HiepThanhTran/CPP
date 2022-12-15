#include <iostream>
using namespace std;

void input(int *&p, int n)
{
    p = new int[n];
    cout << "Nhap " << n << " gia tri cho mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
}
void output(int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
}
int *find(int *p, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i] == x)
            return &p[i];
    }
    return NULL;
}
int main()
{
    int n, x;
    do
    {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    } while (n < 1);
    int *p;
    p = new int[n];
    input(p, n);
    cout << "Mang vua nhap: ";
    output(p, n);
    cout << "Nhap gia tri x bat ky: ";
    cin >> x;
    int *q = find(p, n, x);
    if (q)
    {
        cout << "Vi tri dau tien gia tri x = " << x << " xuat hien la " << q - p << endl;
    }
    else
    {
        cout << "Khong tim thay gia tri x trong mang\n";
    }
    delete[] p;
    system("pause");
    return 0;
}