#include <iostream>
#include <time.h>
#include "Header1.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Tocke t1;
	Tocke t2;
	t1.postavi(15, 7);
	t2.random(1, 6, 3, 8, 2, 10);
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