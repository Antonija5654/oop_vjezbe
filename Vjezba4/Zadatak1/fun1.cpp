#include <iostream>
#include <math.h>
#include "Header1.h"
using namespace std;

void Tocke::postavi(int x, int y, int z)
{
	duzina = x;
	sirina = y;
	visina = z;
}

void Tocke::random(int a, int b, int c, int d, int e, int f)
{
	duzina = (rand() % ((b + 1) - a) + a);
	sirina = (rand() % ((d + 1) - c) + c);
	visina = (rand() % ((f + 1) - e) + e);
}

const double Tocke::duzinaa()
{
	return duzina;
}

const double Tocke::sirinaa()
{
	return sirina;
}

const double Tocke::visinaa()
{
	return visina;
}

const double Tocke::oduzmi_2d(Tocke t2)
{
	double a, b, c;
	a = sqrt(duzina*duzina + sirina * sirina);
	b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina);
	c = a - b;
	return c;
}

const double Tocke::oduzmi_3d(Tocke t2)
{
	double a, b, c;
	a = sqrt(duzina*duzina + sirina * sirina + visina * visina);
	b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina + t2.visina*t2.visina);
	c = a - b;
	return c;
}