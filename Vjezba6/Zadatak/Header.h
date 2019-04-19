#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

namespace OOP {

	class Vec3
	{
	private:
		int x1, x2, y1, y2, z1, z2;
		static int counter;

	public:
		Vec3()
		{
			x1 = 0;
			y1 = 0;
			z1 = 0;
			x2 = 0;
			y2 = 0;
			z2 = 0;
			counter++;
		}

		Vec3(int a, int b, int c, int d, int e, int f)
		{
			x1 = a;
			y1 = b;
			z1 = c;
			x2 = d;
			y2 = e;
			z2 = f;
			counter++;
		}

		friend istream& operator >> (istream& a, Vec3& vektor);

		friend ostream& operator << (ostream& a, Vec3& vektor);

		Vec3 operator = (Vec3 vektor);

		Vec3 operator + (Vec3 vektor);

		Vec3 operator - (Vec3 vektor);

		Vec3 operator * (int br);

		Vec3 operator / (int br);

		Vec3 operator += (Vec3 vektor);

		Vec3 operator -= (Vec3 vektor);

		Vec3 operator *= (int br);

		Vec3 operator /= (int br);

		bool operator == (Vec3 vektor);

		bool operator != (Vec3 vektor);

		int operator * (Vec3 vektor);

		int operator [] (string str);

		Vec3 normaliziraj();

		int vrati_counter();
	};

}

#endif