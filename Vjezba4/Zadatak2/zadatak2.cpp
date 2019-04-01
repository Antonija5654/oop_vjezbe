#include <iostream>
#include <time.h>
#include <string>
#include "Header2.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Gun pistolj;
	string unos;
	while (unos.compare("kraj") != 0)
	{
		cout << "pucaj, reload, kraj"<<endl;
		cin >> unos;
		if (unos.compare("pucaj")==0) 
		{
			pistolj.shoot();
			cout << "preostali br metaka " << pistolj.broj_metaka() << endl;
		}
		else if (unos.compare("reload")==0) 
		{
			pistolj.reload();
		}
	}
	system("pause");
}