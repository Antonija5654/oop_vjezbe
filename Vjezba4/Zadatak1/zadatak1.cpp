#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class tocke {
private:
	double duzina, sirina, visina;

public:
	void postavi(int x = 0, int y = 0, int z = 0)
	{
		duzina = x;
		sirina = y;
		visina = z;
	}

	void random(int a, int b)
	{
		duzina = (rand() % ((b + 1) - a) + a);
		sirina = (rand() % ((b + 1) - a) + a);
		visina = (rand() % ((b + 1) - a) + a);
	}

	const double duzinaa()
	{
		return duzina;
	}

	const double sirinaa()
	{
		return sirina;
	}

	const double visinaa()
	{
		return visina;
	}

	const double oduzmi_2d(tocke t2)
	{
		double a, b, c;
		a = sqrt(duzina*duzina + sirina*sirina);
		b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina);
		c = a - b;
		return c;
	}

	const double oduzmi_3d(tocke t2)
	{
		double a, b, c;
		a = sqrt(duzina*duzina + sirina*sirina + visina*visina);
		b = sqrt(t2.duzina*t2.duzina + t2.sirina*t2.sirina + t2.visina*t2.visina);
		c = a - b;
		return c;
	}
};

int main()
{
	srand(time(NULL));
	tocke t1;
	tocke t2;
	string unos;
	t1.postavi(15, 7);
	t2.random(1, 6);
	cout << "t1 duzina " << t1.duzinaa() <<" ";
	cout << "t1 sirina " << t1.sirinaa() <<" ";
	cout << "t1 visina " << t1.visinaa() << endl;
	cout << "t2 duzina " << t2.duzinaa() << " ";
	cout << "t2 sirina " << t2.sirinaa() << " ";
	cout << "t2 visina " << t2.visinaa() << endl;
	cout << "2d udaljenost " << t1.oduzmi_2d(t2) << endl;
	cout << "3d udaljenost " << t1.oduzmi_3d(t2) << endl;
	system("pause");
}