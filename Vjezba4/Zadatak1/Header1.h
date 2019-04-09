#ifndef FUNH_H
#define FUNH_H
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

class Tocke {
private:
	double duzina, sirina, visina;

public:
	void postavi(int x=0, int y=0, int z=0);

	void random(int a, int b, int c, int d, int e, int f);

	const double duzinaa();

	const double sirinaa();

	const double visinaa();

	const double oduzmi_2d(Tocke t2);

	const double oduzmi_3d(Tocke t2);
};
#endif