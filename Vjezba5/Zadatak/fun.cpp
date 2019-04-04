#include "Header.h"
#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

int provjeri(string tmp)
{
	int mj = 2;
	cout << "tmp koji mi sad triba" << tmp.compare("Apr") << endl;
	if (tmp.compare("Jan") == 0)
		mj = 1;
	else if (tmp.compare("Feb") == 0)
		mj = 2;
	else if (tmp.compare("Mar") == 0)
		mj = 3;
	else if (tmp.compare("Apr") == 0)
		mj = 4;
	else if (tmp.compare("May") == 0)
		mj = 5;
	else if (tmp.compare("Jun") == 0)
		mj = 6;
	else if (tmp.compare("Jul") == 0)
		mj = 7;
	else if (tmp.compare("Aug") == 0)
		mj = 8;
	else if (tmp.compare("Sep") == 0)
		mj = 9;
	else if (tmp.compare("Oct") == 0)
		mj = 10;
	else if (tmp.compare("Nov") == 0)
		mj = 11;
	else if (tmp.compare("Dec") == 0)
		mj = 12;
	cout <<"mj u funkciji provjeri"<< mj<<endl;
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
	int n=sizeof(potr)/sizeof(Potrosnja);
	bool flag = false;
	god = izdvoji_god();
	if ((god - g) < 0)
		cout << "error jos nismo u toj godini" << endl;
	else
	{
		cout << "ispisi n" <<n<< endl;
		if (n != 0)
		{
			for (i = 0; i < n; i++)
			{
				cout << "nakon for petlje" << endl;
				//cout << m << "  " << potr[i].vrati_mj() << "  " << g << "  " << potr[i].vrati_god() << endl;
				if (m == potr[i].vrati_mj() && g == potr[i].vrati_god())
				{
					cout << "taj podatak vec postoji" << endl;
					flag = true;
				}
			}
		}
		if (flag == false)
		{
			if (n != 0)
			{
				for (i = 0; i < n; i++)
				{
					if (potr[i].vrati_god() == 0)
						break;
				}
			}
			potr[i].dodaj(m, g, r);
		}
	}
}

int Food::provjeri_potrosnju()
{
	string tmp = izdvoji_mj();
	int mj = provjeri(tmp);
	int god = izdvoji_god();
	int i, rez_pr_god, rez_sad_god, postotak;
	int n = sizeof(potr) / sizeof(Potrosnja);
	for (i = 0; i < n; i++)
	{
		if (god - 1 == potr[i].vrati_god() && mj == potr[i].vrati_mj())
			rez_pr_god = potr[i].vrati_rez();
		if (god == potr[i].vrati_god() && mj == potr[i].vrati_mj())
			rez_sad_god = potr[i].vrati_rez();
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
	int n = sizeof(potr) / sizeof(Potrosnja);
	for (i = 0; i < n; i++)
		cout << "mjesec: " << potr[i].vrati_mj() << "  " << "godina: " << potr[i].vrati_god() << "  " << "rezultat: " << potr[i].vrati_rez() << endl;
}

void Datum::dodaj_rok(int mj, int god)
{
	m = mj;
	g = god;
}