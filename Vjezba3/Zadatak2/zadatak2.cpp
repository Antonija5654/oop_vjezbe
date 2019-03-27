#include <iostream>
#include <vector>
#include "funh.h"
using namespace std;

int main()
{
	vector<int> v1, v2, novi;
	bool flag = false;
	v1 = dodaj(v1, false);
	v2 = dodaj(v2, false);
	v2 = sortiraj(v2);
	novi = novi_vec(v1, v2, novi);
	ispis(novi);
	system("pause");
}