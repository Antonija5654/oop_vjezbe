#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename TYPE>
class Stack
{
private:
	const int defSize, max;
	int size, top;
	TYPE *stackPtr;
	TYPE niz;
public:
	Stack()
	{
		defSize = 10;
		max = 1000;
		size = defSize;
		top = 0;
		niz = new TYPE[size];
		stackPtr = niz;
	}
	stack(int a)
	{
		if (a > max)
		{
			cout << "velicina niza je veca od max velicine, molimo upisite ponovno" << endl;
			while (a > max)
				cin >> a;
		}
		defSize = 10
		max = 1000
		size = a;
		top = 0;
		niz = new TYPE[size];
		stackPtr = niz;
	}
};
#endif