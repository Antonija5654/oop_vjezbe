#include <iostream>
#include <math.h>
#include "Header2.h"
using namespace std;

void tocke::postavi(int x, int y, int z)
{
	duzina = x;
	sirina = y;
	visina = z;
}

void tocke::random(int a, int b, int c, int d, int e, int f)
{
	duzina = (rand() % ((b + 1) - a) + a);
	sirina = (rand() % ((d + 1) - c) + c);
	visina = (rand() % ((f + 1) - e) + e);
}

const double tocke::duzinaa()
{
	return duzina;
}

const double tocke::sirinaa()
{
	return sirina;
}

const double tocke::visinaa()
{
	return visina;
}

const double tocke::oduzmi_2d(tocke t2)
{
	double a, b, c;
	a = sqrt(duzina*duzina + sirina * sirina);
	b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina);
	c = a - b;
	return c;
}

const double tocke::oduzmi_3d(tocke t2)
{
	double a, b, c;
	a = sqrt(duzina*duzina + sirina * sirina + visina * visina);
	b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina + t2.visina*t2.visina);
	c = a - b;
	return c;
}

void gun::shoot()
{
	if (br_metaka == 0)
	{
		cout << "pistolj je prazan" << endl;
		return;
	}
	br_metaka--;
}

void gun::reload()
{
	br_metaka = kapacitet;
}

void gun::postavi_polozaj()
{
	polozaj.random(1, 6, 3, 8, 2, 10);
}

int gun::broj_metaka()
{
	return br_metaka;
}