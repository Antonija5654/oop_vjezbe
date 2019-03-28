#include "funh.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

vector<int> dodaj(vector<int> v, bool flag, int a, int b, int n)
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

vector<int> sortiraj(vector<int> v2)
{
	int i, j, min, x;
	for (i = 0; i < v2.size(); i++)
	{
		x = i;
		min = v2[i];
		for (j = i; j < v2.size(); j++)
		{
			if (v2[j]<v2[i] && v2[j]<min)
			{
				x = j;
				min = v2[j];
			}
		}
		if (i == x)
			;
		else
			swap(v2[i], v2[x]);
	}
	return v2;
}

vector<int> novi_vec(vector<int> v1, vector<int> v2, vector<int> novi)
{
	int i, p;
	int n = v1.size();
	int l = v1[0], r = v1[n - 1];
	for (i = 0; i < n; i++)
	{
		if (binary_search(v2.begin(), v2.end(), v1[i]))
		{
			novi.push_back(v1[i]);
		}
	}
	return novi;
}
