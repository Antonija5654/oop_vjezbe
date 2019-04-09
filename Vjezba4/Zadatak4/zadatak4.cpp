#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Header4.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int n, vis, sir, a, b, i;
	vector<Meta> v;
	Meta tmp;
	cout << "upisite zeljeni br meta"<<endl;
	cin >> n;
	while (n != 0)
	{
		vis = rand() % 1000;
		sir = rand() % 1000;
		a = rand() % 1000;
		b = rand() % 1000;
		tmp.postavi(vis, sir, a, b);
		tmp.izracunaj_polozaj();
		v.push_back(tmp);
		n--;
	}
	Gun pistolj;
	pistolj.postavi_polozaj();
	while (pistolj.broj_metaka() != 0)
	{
		pistolj.shoot();
		int x = rand() % 1000 - 500;
		int y = rand() % 1000 - 500;
		cout << "ispucano je na polozaj " << x << " " << y << endl;
		for (i = 0; i < v.size(); i++)
		{
			v[i].provjeri_jeli_pogodeno(x, y);
		}
	}
	int brojac = 0;
	for (i = 0; i < v.size(); i++)
	{
		if (v[i].provjera() == 1)
			brojac++;
	}
	cout << "broj pogodenih meta je " << brojac<<endl;
	system("pause");
}