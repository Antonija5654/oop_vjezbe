#ifndef FUNH_H;
#define FUNH_H
#include <iostream>
using namespace std;

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
	void postavi(int vis=10, int sir=5, int a=0, int b=0);

	void izracunaj_polozaj();

	int const gor_des_x();

	int const gor_liv_x();
	
	int const donj_des_x();

	int const donj_liv_x();

	int const gor_des_y();

	int const gor_liv_y();

	int const donj_des_y();

	int const donj_liv_y();
};

#endif