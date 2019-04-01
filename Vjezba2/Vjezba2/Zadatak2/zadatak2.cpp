#include <iostream>
using namespace std;

int *odvoji(int *niz)
{
	int *novi_niz = new int[8];
	int i, j=0;
	for (i = 0; i < 8; i++)
	{
		if (niz[i] % 2 == 0) 
		{
			novi_niz[j] = niz[i];
			j++;
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (niz[i] % 2 == 1)
		{
			novi_niz[j] = niz[i];
			j++;
		}
	}
	return novi_niz;
}

int main()
{
	int niz[] = {7, 13, 4, 9, 10, 11, 2, 27};
	int *novi_niz = odvoji(niz);
	int i;
	for (i = 0; i < 8; i++)
		cout << novi_niz[i]<<" ";
	system("pause");
}