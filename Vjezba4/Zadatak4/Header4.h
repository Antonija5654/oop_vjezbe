#ifndef FUNH_H;
#define FUNH_H
#include <iostream>
using namespace std;

class Tocke {
private:
	int duzina, sirina, visina;

public:
	void postavi(int x = 0, int y = 0, int z = 0);

	void random(int a, int b, int c, int d, int e, int f);

	const int duzinaa();

	const int sirinaa();

	const int visinaa();

	const int oduzmi_2d(Tocke t2);

	const int oduzmi_3d(Tocke t2);
};

class Gun {
private:
	int br_metaka = 6, kapacitet = 6;
	Tocke polozaj;
public:
	void shoot();

	void reload();

	void postavi_polozaj();

	int const broj_metaka();
};

class Tocka {
	friend class Polozaj;
	friend class Meta;
private:
	int x, y;
};

class Polozaj {
	friend class Meta;
private:
	Tocka g_d, g_l, d_d, d_l;
};

class Meta {
private:
	int visina, sirina, a, b;
	string stanje;
	Polozaj p;

public:
	void postavi(int vis = 10, int sir = 5, int a = 0, int b = 0);

	void izracunaj_polozaj();

	int const gor_des_x();

	int const gor_liv_x();

	int const donj_des_x();

	int const donj_liv_x();

	int const gor_des_y();

	int const gor_liv_y();

	int const donj_des_y();

	int const donj_liv_y();

	void provjeri_jeli_pogodeno(int x, int y);

	int provjera();
};

#endif