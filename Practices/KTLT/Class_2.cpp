#include<iostream>
using namespace std;

class TamGiac
{
private:
	int a, b, c;
public:
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
	int getC()
	{
		return c;
	}
	void setA(int cc1)
	{
		a = cc1;
	}
	void setB(int cc2)
	{
		b = cc2;
	}
	void setC(int cc3)
	{
		c = cc3;
	}
	bool checkTG()
	{
		if (a == b && b == c)
			return true;
		return false;
	}
	TamGiac() { a = 0; b = 0; c = 0; };
	~TamGiac() {};
};

int main()
{
	TamGiac tg;
	int cc1, cc2, cc3;
	cout << "Nhap do dai canh thu 1: ";
	cin >> cc1;
	cout << "Nhap do dai canh thu 2: ";
	cin >> cc2;
	cout << "Nhap do dai canh thu 3: ";
	cin >> cc3;
	tg.setA(cc1); tg.setB(cc2); tg.setC(cc3);
	if (tg.checkTG())
		cout << "- Day la tam giac deu\n";
	else
		cout << "- Day khong phai la tam giac deu\n";
	return 0;
}