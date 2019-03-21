#include <iostream>
using namespace std;

void sortiraj(int *niz, int n)
{
	int index, i, j;
	for (i = 0; i < n; i++)
	{
		index = i;
		for (j = i; j < n-1; j++)
		{
			if (niz[j] < niz[index])
				index = j;
		}
		swap(niz[i], niz[index]);
	}
}

void pronadi(int *niz, int *provjera)
{
	int i, j;
	bool flag = true;
	for (i = 0; i < 9; i++)
	{
		flag = true;
		for (j = 0; j < 8; j++)
		{
			if (provjera[i] == niz[j])
				flag = false;
		}
		if (flag == true)
		{
			niz[8] = provjera[i];
		}
	}
	sortiraj(niz);
}

int main()
{
	int* niz = new int[9];
	int provjera[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(provjera) / sizeof(int);
	cout << "upisi niz brojeva izmedu 1 i 9, za kraj upisat 0" << endl;
	int i=0, j;
	int br=1;
	while (br != 0)
	{
		cin >> br;
		niz[i] = br;
		i++;
	}
	pronadi(niz, provjera);
	for (j = 0; j < 9; j++)
		cout << niz[j] << " ";
	system("pause");
}