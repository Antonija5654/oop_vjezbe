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
		vel_niza = vr_u_mj * 2;
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
		for (int i = 0; i < vr_u_mj * 2; i++)
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

class Mlijecni : public Food
{
public:
	Mlijecni(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat) :
		Food(vrst, n, voda, prot, m, uglj, potr_kol, dat) {}
};

class Mesni : public Food
{
public:
	Mesni(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat) :
		Food(vrst, n, voda, prot, m, uglj, potr_kol, dat) {}
};

class Vege : public Food
{
public:
	Vege(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat) :
		Food(vrst, n, voda, prot, m, uglj, potr_kol, dat) {}
};

class Kolaci : public Food
{
public:
	Kolaci(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat) :
		Food(vrst, n, voda, prot, m, uglj, potr_kol, dat) {}
};

class Sir : public Mlijecni
{
private:
	bool provj;
	float samo, dio;
public:
	Sir(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d):
		Mlijecni(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Mlijeko : public Mlijecni
{
private:
	bool provj;
	float samo, dio;
public:
	Mlijeko(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Mlijecni(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Jogurt : public Mlijecni
{
private:
	bool provj;
	float samo, dio;
public:
	Jogurt(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Mlijecni(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Meso : public Mesni
{
private:
	bool provj;
	float samo, dio;
public:
	Meso(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Mesni(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Sunka : public Mesni
{
private:
	bool provj;
	float samo, dio;
public:
	Sunka(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Mesni(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Prsut : public Mesni
{
private:
	bool provj;
	float samo, dio;
public:
	Prsut(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Mesni(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Riza : public Vege
{
private:
	bool provj;
	float samo, dio;
public:
	Riza(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Vege(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Tofu : public Vege
{
private:
	bool provj;
	float samo, dio;
public:
	Tofu(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Vege(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Hummus : public Vege
{
private:
	bool provj;
	float samo, dio;
public:
	Hummus(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, bool p, float s, float d) :
		Vege(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		provj = p;
		samo = s;
		dio = d;
	}
};

class Madjarica : public Kolaci
{
private:
	float samo;
public:
	Madjarica(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, float s) :
		Kolaci(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		samo = s;
	}
};

class Krempita : public Kolaci
{
private:
	float samo;
public:
	Krempita(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, float s) :
		Kolaci(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		samo = s;
	}
};

class Torta : public Kolaci
{
private:
	float samo;
public:
	Torta(string vrst, string n, int voda, int prot, int m, int uglj, int potr_kol, Datum dat, float s) :
		Kolaci(vrst, n, voda, prot, m, uglj, potr_kol, dat)
	{
		samo = s;
	}
};

#endif