#ifndef ZBORJ_H
#define ZBROJ_H
#include <iostream>
using namespace std;

template<typename TYPE>
class Zbroj
{
private:
	TYPE a, b;
public:
	Zbroj(TYPE c, TYPE d)
	{
		a = c;
		b = d;
		cout << "obicna template klasa" << endl;
	}
	
	void sum()
	{
		cout << a + b << endl;
	}
};

template<>
class Zbroj<char>
{
private:
	char a, b;
public:
	Zbroj(char c, char d)
	{
		a = c;
		b = d;
		cout << "specijalizacijska template klasa" << endl;
	}
	
	void sum()
	{
		if (isdigit(a) && isdigit(b))
			cout << char(a + (b - '0')) << endl;
		else if (isalpha(a) && isalpha(b))
			cout << char(a + (b - '`')) << endl;
		else
			cout << "te znakove necu zbrojit" << endl;
	}
};

#endif