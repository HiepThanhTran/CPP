#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    double s1=0, s2=0, s3=0;
    do{
        cout << "Nhap n (n > 0): ";
        cin >> n;
        if(n<1) cout << "Xin nhap lai!\n";
    }while(n<1);

    for(int i=1; i<=n; i++) {
        s1 += pow(i, 2);
        s2 += 1.0/i;
        s3 += 1.0/(2*i-1);
    }
    cout << "S1 = " << s1 << endl;
    cout << "S2 = " << s2 << endl;
    cout << "S3 = " << s3 << endl;
    return 0;
}