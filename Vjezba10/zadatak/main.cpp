#include "Zbroj.h";
#include <iostream>
using namespace std;

int main()
{
	Zbroj<int> a(3, 9);
	Zbroj<char> b('e', 'f');
	Zbroj<char> c('2', '4');
	a.sum();
	b.sum();
	c.sum();
	system("pause");
}