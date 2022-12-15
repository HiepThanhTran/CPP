#include<iostream>
using namespace std;

class PS
{
private:
	int tuso, mauso;
public:
	int getTS()
	{
		return tuso;
	}
	int getMS()
	{
		return mauso;
	}
	void setPS(int a, int b)
	{
		tuso = a;
		mauso = b;
	}
	PS tong2PS(PS ps1, PS ps2)
	{
		PS kq;
		kq.setPS((ps1.tuso * ps2.mauso + ps1.mauso * ps2.tuso), ps1.mauso * ps2.mauso);
		return kq;
	}
	PS hieu2PS(PS ps1, PS ps2)
	{
		PS kq;
		kq.setPS((ps1.tuso * ps2.mauso - ps1.mauso * ps2.tuso), ps1.mauso * ps2.mauso);
		return kq;
	}
	PS tich2PS(PS ps1, PS ps2)
	{
		PS kq;
		kq.setPS(ps1.tuso * ps2.tuso, ps1.mauso * ps2.mauso);
		return kq;
	}
	PS thuong2PS(PS ps1, PS ps2)
	{
		PS kq;
		kq.setPS(ps1.tuso * ps2.mauso, ps1.mauso * ps2.tuso);
		return kq;
	}
	int UCLN(int a, int b)
	{
		if (b == 0) return a;
		return UCLN(b, a % b);
	}
	void rutGonPS(PS& ps)
	{
		int d = UCLN(ps.tuso, ps.mauso);
		ps.setPS(ps.tuso / d, ps.mauso / d);
	}
	void nhapPS(PS& ps)
	{
		do {
			cout << "Nhap vao tu so: ";
			cin >> ps.tuso;
			cout << "Nhap vao mau so: ";
			cin >> ps.mauso;
		} while (ps.mauso == 0);
	}
	void xuatPS(PS ps)
	{
		cout << ps.tuso << "/" << ps.mauso << endl;
	}
};