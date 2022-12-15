#include<iostream>
class GPG
{
private:
	int hours, mins, secs;
public:
	int getH();
	int getM();
	int getS();
	void setTime(int a, int b, int c);
	GPG KC(GPG time1, GPG time2);
};
int GPG::getH()
{
	return hours;
}
int GPG::getM()
{
	return mins;
}
int GPG::getS()
{
	return secs;
}
void GPG::setTime(int a, int b, int c)
{
	hours = a;
	mins = b;
	secs = c;
}
GPG GPG::KC(GPG time1, GPG time2)
{
	GPG KC;
	int sec1 = (time1.getH() * 3600) + (time1.getM() * 60) + time1.getS();
	int sec2 = (time2.getH() * 3600) + (time2.getM() * 60) + time2.getS();
	int kc = abs(sec1 - sec2);
	KC.setTime(kc / 3600, kc / 60 - kc / 3600 * 60, kc % 60);
	return KC;
}