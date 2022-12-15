#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>
const int MAX = 100;

using namespace std;

/*
CÂU 1:
Cài đặt các hàm:
    - void menu()
        1. In ra các số nguyên tố không vượt quá n
        2. Tính tích tất cả các số nguyên tố không vượt quá n
        3. In ra các số hệ 2 từ 1 đến n
        4. Thoát
    - bool KTNT(int n) nếu n là SNT thì trả về giá trị true, ngược lại là false
    - int Tich_NT(int n) hàm trả về giá trị tích tất cả các SNT không vượt quá n
    - int He10_2(int n) hàm dùng để đổi số nguyên hệ thập phân n sang số hệ nhị phân
Viết chương trình lặp lại nhiều lần công việc: in ra menu, nhập vào số nguyên n > 0, và nhập chọn (1-4) để thực hiện chức năng trong menu
*/
void menu()
{
    cout << "1. In ra cac so nguyen to khong vuot qua N\n";
    cout << "2. Tinh tich tat ca cac so nguyen to khong vuot qua N\n";
    cout << "3. In ra cac so he 2 tu 1 den N\n";
    cout << "4. Thoat\n";
}
bool KTNT(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
void inSNT(int n)
{
    for (int i = 1; i < n; i++)
        if (KTNT(i))
            cout << i << " ";
    cout << "\n";
}
int Tich_NT(int n)
{
    int result = 1;
    for (int i = 1; i < n; i++)
        if (KTNT(i))
            result *= i;
    return result;
}
int He10_2(int n)
{
    int result = 0, p = 1;
    while (n != 0)
    {
        result += (n % 2) * p;
        p *= 10;
        n /= 2;
    }
    return result;
}
void inHe10_2(int n)
{
    for (int i = 1; i <= n; i++)
        cout << "He 10: " << i << " -> He 2: " << He10_2(i) << endl;
}
/*
CÂU 2:
Cài đặt các hàm:
    - Hàm tạo mảng ngẫu nhên A có n phần tử, sao cho mỗi phần tử của mảng có giá trị số nguyên từ 1 đến 20
    - Hàm xuất mảng A có n phần tử ra màn hình
    - Hàm trả về vị trí của phần tử nhỏ nhất sau cùng trùng nhau của mảng A
    - Hàm dùng sắp xếp mảng A có giá trị tăng dần
    - Viết hàm in ra số lần xuất hiện của mỗi phần tử trong mảng
Viết chương trình nhập số nguyên n, dùng các hàm đã cài đặt rồi in ra:
    - Mảng các số nguyên ngẫu nhiên A có n phần tử, sao cho mỗi phần tử của mảng chỉ có giá trí số nguyên từ 1 đến 20
    - Vị trí của phần tử nhỏ nhất sau cùng trùng nhau của mảng
    - Mảng các số nguyên A sau khi sắp xếp tăng dần
    - Số lần xuất hiện của mỗi phần tử trong mảng
*/
void taoMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 20 + 1;
}
void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n\n";
}
int viTriNN(int a[], int n)
{
    int min = a[0], viTri = 0;
    for (int i = 1; i < n; i++)
        if (a[i] <= min)
        {
            min = a[i];
            viTri = i;
        }
    return viTri;
}
void sapXepTangDan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}
void tanSuat(int a[], int n)
{
    int b[MAX];
    b[0] = a[0];
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        bool check = true;
        for (int j = i - 1; j >= 0; j--)
            if (a[i] == a[j])
            {
                check = false;
                break;
            }
        if (check == true)
            b[m++] = a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (b[i] == a[j])
                count++;
        cout << "So lan xuat hien cua phan tu " << b[i] << " trong mang la " << count << endl;
    }
}
int main()
{
    srand(int(time(NULL)));
    // CÂU 1:
    int n, chon;
    do{
        menu();
        do{
            cout << "Nhap vao so nguyen n (n > 0): ";
            cin >> n;
            if(n < 1) cout << "\nXin nhap lai so nguyen N!\n";
        }while(n < 1);
        do{
            cout << "Lua chon chuc nang can su dung (1 - 4): ";
            cin >> chon;
            if(chon < 1 || chon > 4) cout << "\nChuc nang hien khong co!\n";
        }while(chon < 1 || chon > 4);
        switch(chon) {
        case 1:
            cout << "Cac so nguyen to khong vuot qua N: ";
            inSNT(n);
            break;
        case 2:
            cout << "Tich tat ca so nguyen to khong vuot qua N = " << Tich_NT(n) << endl;
            break;
        case 3:
            inHe10_2(n);
            break;
        case 4:
            cout << "\nThoat chuong trinh!\n";
            return 0;
        }
        system("pause");
        system("cls");
    }while(chon != 4); 

     //CÂU 2:
    /*int a[MAX], n;
    do{
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        if(n < 1 || n > MAX) cout << "\nSo luong phan tu khong hop le!\n";
    }while(n < 1 || n > MAX);
    taoMang(a, n);
    cout << "Mang A vua tao: ";
    xuatMang(a, n);
    cout << "Vi tri phan tu nho nhat sau cung trung nhau la : " << viTriNN(a, n) + 1 << endl;
    sapXepTangDan(a, n);
    cout << "\nMang A sau khi sap xep tang dan: ";
    xuatMang(a, n);
    tanSuat(a, n); */

    return 0;
}