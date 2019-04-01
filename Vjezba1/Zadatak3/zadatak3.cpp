#include <iostream>

using namespace std;

int& nadi_broj(int niz[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (niz[i] % 10 + (niz[i] % 1000) / 100 == 5)
			return niz[i]
	}
}

int main()
{
	int niz[] = { 1234, 5326, 7895, 2174, 3162 };
	int n = sizeof(niz) / sizeof(int);
	nadi_broj(niz, n) += 1;
	system("pause");
}