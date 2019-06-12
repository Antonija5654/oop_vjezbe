#include <iostream>
#include <vector>
#include <ctime>
#include "XError.h"
#include "ErrorBroj.h"
#include "ErrorOperator.h"
#include "ErrorNull.h"
using namespace std;

int unesi_broj()
{
	int br;
	cout << "upisite broj" << endl;
	cin >> br;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw ErrorBroj();
	}	
	return br;
}

char unesi_operator()
{
	char o;
	cout << "upisite operator" << endl;
	cin >> o;
	if (o != '+' && o != '-' && o != '*' && o != '/')
		throw ErrorOperator();
	return o;
}

int izracunaj(int br1, int br2, char o)
{
	if (o == '+')
		return br1 + br2;
	else if (o == '-')
		return br1 - br2;
	else if (o == '*')
		return br1 * br2;
	else if (o == '/')
	{
		if (br2 == 0)
			throw ErrorNull();
		return br1 / br2;
	}
}

int main()
{
	vector<int> rezultati;
	int br1, br2;
	char o;
	vector<int> rez;
	ofstream dat("errors.log", ios_base::out | ios_base::app);
	while (true)
	{
		try
		{
			br1 = unesi_broj();
			br2 = unesi_broj();
			o = unesi_operator();
			rez.push_back(izracunaj(br1, br2, o));
		}
		catch (XError &x)
		{
			x.ispisi(dat);
		}
	}

	system("pause");
}