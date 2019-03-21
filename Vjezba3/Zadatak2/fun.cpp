#include "funh.h"
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> dodaj(vector<int> v, bool flag, int a = 0, int b = 100, int n = 5)
{
	int br = 0, broj;
	if (flag == true)
	{
		while (br < n)
		{
			cin >> broj;
			if (broj<a || broj>b)
			{
				cout << "neispravan unos" << endl;
			}
			else
			{
				v.push_back(broj);
				br++;
			}
		}
	}
	else
	{
		srand(time(NULL));
		while (br < n)
		{
			broj = a + (rand() % (b + 1));
			v.push_back(broj);
			br++;
		}
	}
	return v;
}

void ispis(vector<int> v)
{
	int i;
	for (i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}