#include <iostream>
#include <string>
#include "Header3.h"
using namespace std;

int main()
{
	Meta m;
	m.postavi();
	m.izracunaj_polozaj();
	cout << "gornja desna tocka " << m.gor_des_x() << " " << m.gor_des_y() << endl;
	cout << "donja desna tocka " << m.donj_des_x() << " " << m.donj_des_y() << endl;
	cout << "donja liva tocka " << m.donj_liv_x() << " " << m.donj_liv_y() << endl;
	cout << "gornja liva tocka " << m.gor_liv_x() << " " << m.gor_liv_y() << endl;
	system("pause");
}