#include "Zbroj.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Zbroj<int> a(3, 9);
	Zbroj<char> b('e', 'f');
	Zbroj<char> c('2', '4');
	a.sum();
	b.sum();
	c.sum();
	
	Stack<int> s;
	string unos = "dodaj";
	int br;
	while (unos.compare("kraj") != 0)
	{
		cin >> br;
		s.push(br);
		cout << "dodaj ili kraj" << endl;
		cin >> unos;
	}
	cout << s.pop() << endl;
	cout << s.dohvati_zadnji_element() << endl;
	cout << s.dohvati_velicinu() << endl;

	system("pause");
}