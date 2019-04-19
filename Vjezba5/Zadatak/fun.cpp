#include "Header.h"
#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

int provjeri(string tmp)
{
	int mj = 0;
	if (tmp[0] == 'J' && tmp[1] == 'a' && tmp[2] == 'n')
		mj = 1;
	else if (tmp[0] == 'F' && tmp[1] == 'e' && tmp[2] == 'b')
		mj = 2;
	else if (tmp[0] == 'M' && tmp[1] == 'a' && tmp[2] == 'r')
		mj = 3;
	else if (tmp[0]=='A' && tmp[1] == 'p' && tmp[2] == 'r')
		mj = 4;
	else if (tmp[0] == 'M' && tmp[1] == 'a' && tmp[2] == 'y')
		mj = 5;
	else if (tmp[0] == 'J' && tmp[1] == 'u' && tmp[2] == 'n')
		mj = 6;
	else if (tmp[0] == 'J' && tmp[1] == 'u' && tmp[2] == 'l')
		mj = 7;
	else if (tmp[0] == 'A' && tmp[1] == 'u' && tmp[2] == 'g')
		mj = 8;
	else if (tmp[0] == 'S' && tmp[1] == 'e' && tmp[2] == 'p')
		mj = 9;
	else if (tmp[0] == 'O' && tmp[1] == 'c' && tmp[2] == 't')
		mj = 10;
	else if (tmp[0] == 'N' && tmp[1] == 'o' && tmp[2] == 'v')
		mj = 11;
	else if (tmp[0] == 'D' && tmp[1] == 'e' && tmp[2] == 'c')
		mj = 12;
	return mj;
}

string izdvoji_mj()
{
	time_t curr_time;
	curr_time = time(NULL);
	string tm = ctime(&curr_time);
	string tmp = "";
	tmp += tm[4];
	tmp += tm[5];
	tmp += tm[6];
	tmp += '\0';
	return tmp;
}

int izdvoji_god()
{
	time_t curr_time;
	curr_time = time(NULL);
	string tm = ctime(&curr_time);
	int god;
	god = tm[20] - '0';
	god = god * 10 + (tm[21] - '0');
	god = god * 10 + (tm[22] - '0');
	god = god * 10 + (tm[23] - '0');
	return god;
}

int Datum::izracunaj()
{
	int mj, god, mjr, godr, vr_u_mj;
	string tmp = izdvoji_mj();
	mjr = m;
	godr = g;
	mj = provjeri(tmp);
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
			cout << "vel niza 1:" << vel_niza << endl;
			potr[i].dodaj(m, g, r);
			cout << "vel niza 2:" << vel_niza << endl;
		}
	}
}

int Food::provjeri_potrosnju()
{
	string tmp = izdvoji_mj();
	int mj = provjeri(tmp);
	cout << "mjesec" << mj << endl;
	int god = izdvoji_god();
	int i, rez_pr_god, rez_sad_god, postotak;
	cout <<"godina"<< god << endl;
	for (i = 0; i < vel_niza; i++)
	{
		if (god - 1 == potr[i].vrati_god() && mj == potr[i].vrati_mj())
			rez_pr_god = potr[i].vrati_rez();
		else if (god == potr[i].vrati_god() && mj == potr[i].vrati_mj())
			rez_sad_god = potr[i].vrati_rez();
		else
		{
			cout << "nema dovoljno podataka" << endl;
			return 0;
		}
	}
	postotak = rez_pr_god / 10;
	if (rez_sad_god > rez_pr_god + postotak)
		return 1;
	else if (rez_sad_god < rez_pr_god - postotak)
		return -1;
	else
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
	cout << "Velicina niza: " << vel_niza << endl;
	for (i = 0; i < vel_niza; i++)
		cout << "mjesec: " << potr[i].vrati_mj() << "  " << "godina: " << potr[i].vrati_god() << "  " << "rezultat: " << potr[i].vrati_rez() << endl;
}

void Datum::dodaj_rok(int mj, int god)
{
	m = mj;
	g = god;
}