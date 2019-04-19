#include <iostream>
#include <math.h>
#include "Header.h"
using namespace std;

int Vec3::counter = 0;

istream& operator >> (istream& a, Vec3& vektor)
{
	cout << "upisi x1, y1, z1, x2, y2, z2" << endl;
	a >> vektor.x1 >> vektor.y1 >> vektor.z1 >> vektor.x2 >> vektor.y2 >> vektor.z2;
	return a;
}

ostream& operator << (ostream& a, Vec3& vektor)
{
	a << "x1: " << vektor.x1 << "  " << "y1: " << vektor.y1 << "  " << "z1: " << vektor.z1 << "  " << "x2: " << vektor.x2 << "  " << "y2: " << vektor.y2 << "  " << "z2: " << vektor.z2 << endl;
	return a;
}

Vec3 Vec3::operator = (Vec3 vektor)
{
	x1 = vektor.x1;
	y1 = vektor.y1;
	z1 = vektor.z1;
	x2 = vektor.x2;
	y2 = vektor.y2;
	z2 = vektor.z2;
	return *this;
}

Vec3 Vec3::operator + (Vec3 vektor)
{
	Vec3 novi(x1, y1, z1, vektor.x2, vektor.y2, vektor.z2);
	return novi;
}

Vec3 Vec3::operator - (Vec3 vektor)
{
	Vec3 novi(x1, y1, z1, vektor.x1, vektor.y1, vektor.z1);
	return novi;
}

Vec3 Vec3::operator * (int br)
{
	Vec3 novi(x1, y1, z1, x2*br, y2*br, z2*br);
	return novi;
}

Vec3 Vec3::operator / (int br)
{
	Vec3 novi(x1, y1, z1, x2/br, y2/br, z2/br);
	return novi;
}

Vec3 Vec3::operator += (Vec3 vektor)
{
	x2 = vektor.x2;
	y2 = vektor.y2;
	z2 = vektor.z2;
	return *this;
}

Vec3 Vec3::operator -= (Vec3 vektor)
{
	x2 = vektor.x1;
	y2 = vektor.y1;
	z2 = vektor.z1;
	return *this;
}

Vec3 Vec3::operator *= (int br)
{
	x2 = x2 * br;
	y2 = y2 * br;
	z2 = z2 * br;
	return *this;
}

Vec3 Vec3::operator /= (int br)
{
	x2 = x2 / br;
	y2 = y2 / br;
	z2 = z2 / br;
	return *this;
}

bool Vec3::operator == (Vec3 vektor)
{
	if (x1 == vektor.x1 && y1 == vektor.y1 && z1 == vektor.z1 && x2 == vektor.x2 && y2 == vektor.y2 && z1 == vektor.z2)
		return true;
	else
		return false;
}

bool Vec3::operator != (Vec3 vektor)
{
	if (x1 != vektor.x1 || y1 != vektor.y1 || z1 != vektor.z1 || x2 != vektor.x2 || y2 != vektor.y2 || z1 != vektor.z2)
		return true;
	else
		return false;
}

int Vec3::operator * (Vec3 vektor)
{
	return (x2 - x1)*(vektor.x2 - vektor.x1) + (y2 - y1)*(vektor.y2 - vektor.y1) + (z2 - z1)*(vektor.z2 - vektor.z1);
}

int Vec3::operator [] (string str)
{
	if (str.compare("0") == 0 || str.compare("x1") == 0)
		return x1;
	else if (str.compare("1") == 0 || str.compare("y1") == 0)
		return y1;
	else if (str.compare("2") == 0 || str.compare("z1") == 0)
		return z1;
	else if (str.compare("3") == 0 || str.compare("x2") == 0)
		return x2;
	else if (str.compare("4") == 0 || str.compare("y2") == 0)
		return y2;
	else if (str.compare("5") == 0 || str.compare("z2") == 0)
		return z2;
}

Vec3 Vec3::normaliziraj()
{
	float rez = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
	x2 = x1 + ((x2 - x1) / rez);
	y2 = y1 + ((y2 - y1) / rez);
	z2 = z1 + ((z2 - z1) / rez);
	return *this;
}

int Vec3::vrati_counter()
{
	return counter;
}