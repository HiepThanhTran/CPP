#include <iostream>

using namespace std;

int main10()
{
	char kytu;
	int maASCII;
	cout << "Nhap vao 1 ky tu: ";
	cin >> kytu;
	cout << "Ma ASCII cua ky tu " << kytu << " la: " << (int)kytu << endl;
	cout << "Nhap vao 1 so nguyen trong pham vi 0..255: ";
	cin >> maASCII;
	cout << "Ky tu co ma ASCII " << maASCII << " la: " << (char)maASCII << endl;
	system("pause");
	return 0;
}
