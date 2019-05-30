#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename TYPE>
class Stack
{
private:
	const int defSize=10, max=1000;
	int size, top;
	TYPE *stackPtr;
	TYPE *niz;
public:
	Stack()
	{
		size = defSize;
		top = 0;
		niz = new TYPE[size];
		stackPtr = niz;
	}
	
	Stack(int a)
	{
		if (a > max)
		{
			cout << "velicina niza je veca od max velicine, molimo upisite ponovno" << endl;
			while (a > max)
				cin >> a;
		}
		size = a;
		top = 0;
		niz = new TYPE[size];
		stackPtr = niz;
	}
	
	bool provjeri_jeli_popunjeno()
	{
		if (top == size)
			return true;
		else
			return false;
	}

	bool provjeri_jeli_prazno()
	{
		if (top == 0)
			return true;
		else
			return false;
	}

	void push(TYPE pod)
	{
		if (this->provjeri_jeli_popunjeno())
		{
			cout << "niz je popunjen" << endl;
			return;
		}
		else
		{
			niz[top] = pod;
			top++;
			stackPtr = &niz[top];
		}
	}
	
	TYPE pop()
	{
		if (this->provjeri_jeli_prazno())
		{
			cout << "niz je prazan" << endl;
			return NULL;
		}
		else
		{
			top--;
			stackPtr = &niz[top];
			return niz[top];
		}
	}

	TYPE dohvati_zadnji_element()
	{
		if (this->provjeri_jeli_prazno())
		{
			cout << "niz je prazan" << endl;
			return NULL;
		}
		else
			return niz[top - 1];
	}

	int dohvati_velicinu()
	{
		return size;
	}
};
#endif