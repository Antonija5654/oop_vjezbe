#include <iostream>
#include "Header4.h"
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

const int Tocke::duzinaa()
{
	return duzina;
}

const int Tocke::sirinaa()
{
	return sirina;
}

const int Tocke::visinaa()
{
	return visina;
}

const int Tocke::oduzmi_2d(Tocke t2)
{
	double a, b, c;
	a = sqrt(duzina*duzina + sirina * sirina);
	b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina);
	c = a - b;
	return c;
}

const int Tocke::oduzmi_3d(Tocke t2)
{
	double a, b, c;
	a = sqrt(duzina*duzina + sirina * sirina + visina * visina);
	b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina + t2.visina*t2.visina);
	c = a - b;
	return c;
}

void Gun::shoot()
{
	if (br_metaka == 0)
	{
		cout << "pistolj je prazan" << endl;
		return;
	}
	br_metaka--;
}

void Gun::reload()
{
	br_metaka = kapacitet;
}

void Gun::postavi_polozaj()
{
	polozaj.random(1, 6, 3, 8, 2, 10);
}

const int Gun::broj_metaka()
{
	return br_metaka;
}

void Meta::postavi(int vis, int sir, int a, int b)
{
	visina = vis;
	sirina = sir;
	p.d_l.x = a;
	p.d_l.y = b;
	stanje = "nepogodeno";
}

void Meta::izracunaj_polozaj()
{
	p.g_l.y = p.d_l.y + visina;
	p.g_l.x = p.d_l.x;
	p.d_d.x = p.d_l.x - sirina;
	p.d_d.y = p.d_l.y;
	p.g_d.x = p.d_l.x - sirina;
	p.g_d.y = p.d_l.y + visina;
}

int const Meta::gor_des_x()
{
	return p.g_d.x;
}

int const Meta::gor_liv_x()
{
	return p.g_l.x;
}

int const Meta::donj_des_x()
{
	return p.d_d.x;
}

int const Meta::donj_liv_x()
{
	return p.d_l.x;
}

int const Meta::gor_des_y()
{
	return p.g_d.y;
}

int const Meta::gor_liv_y()
{
	return p.g_l.y;
}

int const Meta::donj_des_y()
{
	return p.d_d.y;
}

int const Meta::donj_liv_y()
{
	return p.d_l.y;
}

void Meta::provjeri_jeli_pogodeno(int x, int y)
{
	if (x > p.g_d.x && x < p.d_l.x)
	{
		if (y < p.g_d.y && y > p.d_l.y)
		{
			cout << "meta:: gornji desni kut: (" << p.g_d.x << " " << p.g_d.y << "), donji livi kut: (" << p.d_l.x << " " << p.d_l.y << ")" << endl;
			stanje = "pogodeno";
		}
	}
}

int Meta::provjera()
{
	if (stanje.compare("pogodeno") == 0)
		return 1;
	else
		return 0;
}