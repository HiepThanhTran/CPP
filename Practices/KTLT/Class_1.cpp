#include<iostream>
using namespace std;

class GIO
{
private:
	int hour, minutes;
public:
	int getHour();
	int getMinutes();
	void setHour(int h);
	void setMinutes(int m);
	bool checkHopLe();
	GIO() { hour = 0; minutes = 0; };
	~GIO(){};
};
int GIO::getHour()
{
	return hour;
}
int GIO::getMinutes()
{
	return minutes;
}
void GIO::setHour(int h)
{
	hour = h;
}
void GIO::setMinutes(int m)
{
	minutes = m;
}
bool GIO::checkHopLe()
{
	if (hour >= 0 && hour <= 23 && minutes >= 0 && minutes <= 59)
		return true;
	return false;
}

int main()
{
	GIO a;
	int h, m;
	cout << "Nhap gia tri gio: ";
	cin >> h;
	cout << "Nhap gia tri phut: ";
	cin >> m;
	a.setHour(h);
	a.setMinutes(m);
	if (a.checkHopLe())
		cout << a.getHour() << ":" << a.getMinutes() << " la gio hop le\n";
	else
		cout << a.getHour() << ":" << a.getMinutes() << " khong hop le\n";
	return 0;
}