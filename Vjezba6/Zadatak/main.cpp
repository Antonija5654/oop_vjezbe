#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Vec3 vektor1;
	cin >> vektor1;
	Vec3 vektor2;
	cin >> vektor2;
	Vec3 vektor3;
	vektor3 = vektor1 + vektor2;
	cout << "operator + " << vektor3;
	vektor3 = vektor1 - vektor2;
	cout << "operator - " << vektor3;
	vektor3 = vektor1 * 5;
	cout << "operator * " << vektor3;
	vektor3 = vektor1 / 2;
	cout << "operator / " << vektor3;
	vektor2 += vektor1;
	cout << "operator += " << vektor2;
	vektor2 -= vektor1;
	cout << "operator -= " << vektor2;
	vektor2 *= 3;
	cout << "operator *= " << vektor2;
	vektor2 /= 3;
	cout << "operator /= " << vektor2;
	cout << "vektor1 " << vektor1;
	cout << "vektor2 " << vektor2;
	cout << "vektor3 " << vektor3;
	if (vektor1 == vektor2)
		cout << "isti su operator ==" << endl;
	else 
		cout << "nisu isti operator ==" << endl;
	if (vektor2 != vektor3)
		cout << "nisu isti operator !=" << endl;
	else
		cout << "isti su operator !=" << endl;
	int rez = vektor1 * vektor2;
	cout << "skalarni produkt " << rez << endl;
	cout << "operator [] " << vektor1["2"] << endl;
	vektor1.normaliziraj();
	cout << "vektor 1 nakon normalizacije " << vektor1;
	cout << "counter " << vektor1.vrati_counter() << endl;
	system("pause");
}