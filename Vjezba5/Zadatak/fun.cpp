#include "Header.h"
#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

int izdvoji_god() {
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	return tmp->tm_year + 1900;
}

int izdvoji_mj() {
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	return tmp->tm_mon + 1;
}

int Datum::izracunaj()
{
	int mj, god, mjr, godr, vr_u_mj;
	mj = izdvoji_mj();
	mjr = m;
	godr = g;
	god = izdvoji_god();
	god = god * 12 + mj;
	godr = godr * 12 + mjr;
	vr_u_mj = godr - god;
	return vr_u_mj;
}

void Food::povecaj_potr_kol()
{
	potrebna_kolicina++;
}

void Food::smanji_potr_kol()
{
	potrebna_kolicina--;
}

void Potrosnja::dodaj(int m, int g, int r)
{
	mj = m;
	god = g;
	rez = r;
}

int const Potrosnja::vrati_mj()
{
	return mj;
}

int const Potrosnja::vrati_god()
{
	return god;
}

int const Potrosnja::vrati_rez()
{
	return rez;
}

void Food::dodaj_u_niz()
{
	int m, g, r, god, i=0;
	cout << "upisite mjesec, godinu i rezultat" << endl;
	cin >> m;
	cin >> g;
	cin >> r;
	bool flag = false;
	god = izdvoji_god();
	if ((god - g) < 0)
		cout << "error jos nismo u toj godini" << endl;
	else
	{
		for (i = 0; i < vel_niza; i++)
		{
			if (m == potr[i].vrati_mj() && g == potr[i].vrati_god())
			{
				cout << "taj podatak vec postoji" << endl;
				flag = true;
			}
		}
		if (flag == false)
		{
			for (i = 0; i < vel_niza; i++)
			{
				if (potr[i].vrati_god() == 0)
					break;
			}
			potr[i].dodaj(m, g, r);
		}
	}
}

int Food::provjeri_potrosnju()
{
	int mj = izdvoji_mj();
	int god = izdvoji_god();
	int i, rez_pr_god, rez_sad_god, postotak;
	bool flag1 = false, flag2 = false;
	for (i = 0; i < vel_niza; i++)
	{
		if (god - 1 == potr[i].vrati_god() && mj == potr[i].vrati_mj()) 
		{
			rez_pr_god = potr[i].vrati_rez();
			flag1 = true;
		}
		else if (god == potr[i].vrati_god() && mj == potr[i].vrati_mj()) 
		{
			rez_sad_god = potr[i].vrati_rez();
			flag1 = true;
		}
	}
	if (flag1 == true && flag2 == true) 
	{
		postotak = rez_pr_god / 10;
		if (rez_sad_god > rez_pr_god + postotak)
			return 1;
		else if (rez_sad_god < rez_pr_god - postotak)
			return -1;
		else
			return 0;
	}
	cout << "nema dovoljno podataka" << endl;
	return 0;
}

void const Food::ispisi()
{
	cout << "vrsta: " << vrsta << endl;
	cout << "naziv: " << naziv << endl;
	cout << "kolicina vode u 100 gm hrane: " << kol_vode << endl;
	cout << "kolicina proteina u 100 gm hrane: " << proteini << endl;
	cout << "kolicina masti u 100 gm hrane: " << mast << endl;
	cout << "kolicina ugljikohidrata u 100 gm hrane: " << ugljhidrati << endl;
	cout << "dnevna potrebna kolicina u kg: " << potrebna_kolicina << endl;
	cout << "podaci o potrosnji:" << endl;
	int i;
	for (i = 0; i < vel_niza; i++)
	{
		if(potr[i].vrati_mj() != 0 && potr[i].vrati_god() != 0)
			cout << "mjesec: " << potr[i].vrati_mj() << "  " << "godina: " << potr[i].vrati_god() << "  " << "rezultat: " << potr[i].vrati_rez() << endl;
	}
}

void Datum::dodaj_rok(int mj, int god)
{
	m = mj;
	g = god;
}