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

int binarySearch(vector<int> v2, int l, int r, int x)
{
	//x sta trazin, l pocetak, r kraj
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (v2[mid] == x)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (v2[mid] > x)
			return binarySearch(v2, l, mid - 1, x);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(v2, mid + 1, r, x);
	}

	// We reach here when element is not 
	// present in array 
	return -1;
}

vector<int> novi_vec(vector<int> v1, vector<int> v2, vector<int> novi)
{
	int i, p, x = 0;
	int n = v1.size();
	int l = v1[0], r = v1[n - 1];
	for (i = 0; i < n; i++)
	{
		p = binarySearch(v2, l, r, v1[i]);
		if (p == -1)
		{
			novi[x] = v1[i];
			x++;
		}
	}
	return novi;
}
