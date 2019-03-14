#include <iostream>
using namespace std;

void sortiraj(int *niz)
{
	
}

int *pronadi(int *niz, int *provjera, int n)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (provjera[i] == niz[j])
				;
			else
			{
				niz[n + 1] = provjera[i];
				n++;
			}
		}
	}
	return niz;
}

void main()
{
	int* niz = new int[];
	int provjera[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "upisi niz brojeva izmedu 1 i 9, za kraj upisat 0" << endl;
	int i=0;
	int br=1;
	while (br != 0)
	{
		cin >> br;
		niz[i] = br;
		i++;
	}
	int n = sizeof(niz) / sizeof(int);
}