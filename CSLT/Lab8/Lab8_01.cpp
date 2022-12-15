#include <iostream>
#include <math.h>

using namespace std;
const int MAX = 50;

void input(double alpha[]) {
    for(int i = 0; i < MAX; i++) {
        cout << "Nhap gia tri phan tu a[" << i << "] = ";
        cin >> alpha[i];
    }
}
void BL(double alpha[]) {
    for(int i = 0; i < MAX; i++) {
        if(i < MAX / 2) {
            cout << pow(alpha[i], 2) << "\t";
        }else{
            cout << pow(alpha[i], 3) << "\t";
        }
        if(i % 10 == 9) cout << "\n";
    }
}
int main() {
	double alpha[MAX];
    input(alpha);
    cout << "\t\t\t\t KET QUA\n";
    BL(alpha);
    system("pause");
	return 0;
}