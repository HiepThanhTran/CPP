#include"PhanSo.h"

int main()
{
	PS ps1, ps2, tong, hieu, tich, thuong;
	cout << "Nhap phan so thu 1\n";
	ps1.nhapPS(ps1);
	cout << "\nNhap Phan so thu 2\n";
	ps2.nhapPS(ps2);

	tong = tong.tong2PS(ps1, ps2);
	tong.rutGonPS(tong);

	hieu = hieu.hieu2PS(ps1, ps2);
	hieu.rutGonPS(hieu);

	tich = tich.tich2PS(ps1, ps2);
	tich.rutGonPS(tich);

	thuong = thuong.thuong2PS(ps1, ps2);
	thuong.rutGonPS(thuong);

	cout << "Tong 2 phan so: ";
	tong.xuatPS(tong);
	cout << "Hieu 2 phan so: ";
	hieu.xuatPS(hieu);
	cout << "Tich 2 phan so: ";
	tich.xuatPS(tich);
	cout << "Thuong 2 phan so: ";
	thuong.xuatPS(thuong);
	return 0;
}