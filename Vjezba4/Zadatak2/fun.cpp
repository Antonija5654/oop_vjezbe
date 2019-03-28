#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class tocke {
private:
	double duzina, sirina, visina;

public:
	void postavi(int x = 0, int y = 0, int z = 0)
	{
		duzina = x;
		sirina = y;
		visina = z;
	}

	void random(int a, int b)
	{
		duzina = (rand() % ((b + 1) - a) + a);
		sirina = (rand() % ((b + 1) - a) + a);
		visina = (rand() % ((b + 1) - a) + a);
	}

	const double duzinaa()
	{
		return duzina;
	}

	const double sirinaa()
	{
		return sirina;
	}

	const double visinaa()
	{
		return visina;
	}

	const double oduzmi_2d(tocke t2)
	{
		double a, b, c;
		a = sqrt(duzina*duzina + sirina * sirina);
		b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina);
		c = a - b;
		return c;
	}

	const double oduzmi_3d(tocke t2)
	{
		double a, b, c;
		a = sqrt(duzina*duzina + sirina * sirina + visina * visina);
		b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina + t2.visina*t2.visina);
		c = a - b;
		return c;
	}
};

class gun {
private:
	int br_metaka, kapacitet;

public:
	void shoot()
	{
		br_metaka--;
	}
	void reload()
	{
		br_metaka = kapacitet;
	}
};