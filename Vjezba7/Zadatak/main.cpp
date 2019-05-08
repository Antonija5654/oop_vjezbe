#include <iostream>
#include "Header.h"
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<Food*> hrana;
	Datum tmp;
	tmp.dodaj_rok(5, 2020);
	Sir* tmp_sir = new Sir("gl jelo", "steak", 5, 5, 5, 5, 5, tmp, 0, 0);
	string unos;
	while (unos.compare("kraj") != 0)
	{
		cin >> *tmp_sir;
		cout << "dodaj ili kraj" << endl;
		cin >> unos;
	}
	hrana.push_back(tmp_sir);
	Meso* tmp_meso = new Meso("gl jelo", "steak", 5, 5, 5, 5, 5, tmp, 10, 10);
	hrana.push_back(tmp_meso);
	Prsut* tmp_prsut = new Prsut("gl jelo", "steak", 5, 5, 5, 5, 5, tmp, 2, 1.2);
	hrana.push_back(tmp_prsut);
	Riza* tmp_riza = new Riza("gl jelo", "steak", 5, 5, 5, 5, 5, tmp, 1, 0.6);
	hrana.push_back(tmp_riza);
	Torta* tmp_torta = new Torta("gl jelo", "steak", 5, 5, 5, 5, 5, tmp, 0.2);
	hrana.push_back(tmp_torta);
	int i;
	for (i = 0; i < hrana.size(); i++)
		cout << *hrana[i] << endl;
	system("pause");
}