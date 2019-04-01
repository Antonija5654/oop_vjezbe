#include <iostream>
#include "Header3.h"
using namespace std;

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