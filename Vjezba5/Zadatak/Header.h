#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
using namespace std;

class Datum {
private:
	int m, g;

public:
	int izracunaj();

	void dodaj_rok(int mj, int god);
};

class Potrosnja {
private:
	int mj, god, rez;

public:
	Potrosnja()
	{
		mj = 0;
		god = 0;
		rez = 0;
	}

	void dodaj(int m, int g, int r);

	int const vrati_mj();

	int const vrati_god();

	int const vrati_rez();
};

class Food {
private:
	string vrsta, naziv;
	int kol_vode, proteini, mast, ugljhidrati, potrebna_kolicina, vel_niza;
	Datum rok;
	Potrosnja *potr;

public:
	Food(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat)
	{
		vrsta = vrst;
		naziv = n;
		kol_vode = voda;
		proteini = prot;
		mast = m;
		ugljhidrati = uglj;
		potrebna_kolicina = potr_kol;
		rok = dat;
		int vr_u_mj = rok.izracunaj();
		potr = new Potrosnja[vr_u_mj * 2];
		vel_niza = vr_u_mj*2;
		cout << "stvoreno" << endl;
	}

	Food(const Food& copy) {
		vrsta = copy.vrsta;
		naziv = copy.naziv;
		kol_vode = copy.kol_vode;
		proteini = copy.proteini;
		mast = copy.mast;
		ugljhidrati = copy.ugljhidrati;
		potrebna_kolicina = copy.potrebna_kolicina;
		rok = copy.rok;
		vel_niza = copy.vel_niza;
		int vr_u_mj = rok.izracunaj();
		potr = new Potrosnja[vr_u_mj * 2];
		for (int i = 0; i < vr_u_mj*2; i++) 
			potr[i] = copy.potr[i];
		cout << "kopirano" << endl;
	}

	~Food()
	{
		delete[] potr;
		cout << "izbrisano" << endl;
	}

	void povecaj_potr_kol();

	void smanji_potr_kol();

	void dodaj_u_niz();

	int provjeri_potrosnju();

	void const ispisi();
};

#endif