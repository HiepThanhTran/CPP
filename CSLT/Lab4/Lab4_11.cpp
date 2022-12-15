//Viết chương trình nhận vào 1 số ở dạng nhị phân.
//Xuất ra màn hình kết quả số đó chuyển qua hệ thập phân.

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int np, temp = 0, sm = 0, s = 0;
    cout << "Nhap so nhi phan can chuyen doi: ";
    cin >> np;
    while(np > 0) {
        temp = np % 10;
        s += temp*pow(2,sm);
        np = np / 10;
        sm++;
    }
    cout << "So nhi phan da chuyen doi sang thap phan: " << s << endl;
    return 0;
}