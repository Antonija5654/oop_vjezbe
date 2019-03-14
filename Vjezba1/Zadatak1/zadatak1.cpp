#include <iostream>

using namespace std;

int main()
{
	int niz[] = { 1, 3, 6, 7, 2, 7, 1, 9, 7, 3, 1, 7 };
	int provjera[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i, j, m = 0;
	int n = sizeof(niz) / sizeof(int);
	for (i = 0; i < n; i++)
	{
		bool flag = true;
		int brojac = 0;
		for (int x = 0; x < 9; x++)
		{
			if (niz[i] == provjera[x])
				flag = false;
		}
		if (flag)
		{
			provjera[m] = niz[i];
			m++;
			for (j = 0; j < n; j++)
			{
				if (niz[i] == niz[j])
					brojac++;
			}
			cout << niz[i] << "-" << brojac << endl;
		}

	}
	system("pause");
}