#include <iostream>
#include "Header.h"
#include <vector>
#include <string>

int main()
{
	vector<Food> hrana;
	string vrsta, naziv;
	int kol_vode, proteini, mast, ugljhidrati, potrebna_kolicina;
	Datum rok;
	int mj, god, i, postotak;
	string unos = "";
	cout << "unesite vrstu" << endl;
	cin >> vrsta;
	cout << "unesite naziv" << endl;
	cin >> naziv;
	cout << "unesite kolicinu vode" << endl;
	cin >> kol_vode;
	cout << "unesite kolicinu proteina" << endl;
	cin >> proteini;
	cout << "unesite kolicinu masti" << endl;
	cin >> mast;
	cout << "unesite kolicinu ugljikohidrata" << endl;
	cin >> ugljhidrati;
	cout << "unesite potrebnu kolicinu" << endl;
	cin >> potrebna_kolicina;
	cout << "upisite mjesec i godinu za rok trajanja" << endl;
	cin >> mj;
	cin >> god;
	rok.dodaj_rok(mj, god);
	Food tmp(vrsta, naziv, kol_vode, proteini, mast, ugljhidrati, potrebna_kolicina, rok);
	while (unos.compare("kraj") != 0)
	{
		cout << "dodaj ili kraj" << endl;
		cin >> unos;
		if (unos.compare("dodaj") == 0)
		{
			tmp.dodaj_u_niz();
		}
	}
	hrana.push_back(tmp);
	for (i = 0; i < hrana.size(); i++)
	{
		hrana[i].ispisi();
		cout << "Ispisano\n";
		postotak = hrana[i].provjeri_potrosnju();
		if (postotak == 0)
		{
			cout << "potrosnja se nije smanjila ni povecala za 10% ili vise" << endl;
		}
		else if (postotak == 1)
		{
			cout << "potrosnja se povecala za 10% ili vise" << endl;
			hrana[i].povecaj_potr_kol();
			cout << "ispis nakon povecane potrebne kolicine" << endl;
			hrana[i].ispisi();
		}
		else if (postotak == -1)
		{
			cout << "potrosnja se smanjila za 10% ili vise" << endl;
			hrana[i].smanji_potr_kol();
			cout << "ispis nakon smanjene potrebne kolicine" << endl;
			hrana[i].ispisi();
		}
	}
	system("pause");
}