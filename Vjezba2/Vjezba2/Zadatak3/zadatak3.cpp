#include <iostream>
#include <string>
using namespace std;

typedef struct vektor {
	int *niz;
	int log, fiz;

void vector_new(int init)
{
	log = 0;
	fiz = init;
	niz = new int[init];
}

void vector_delete()
{
	delete[] niz;
}

void vector_push_back()
{
	if (log == fiz)
	{
		niz = (int*)realloc(niz, (fiz * 2)*sizeof(int));
		fiz = fiz * 2;
	}
	int br;
	cout << "unesite broj" << endl;
	cin >> br;
	niz[log] = br;
	log++;
}

int vector_pop_back()
{
	if (log == 0)
		return NULL;
	log--;
	return niz[log];
}

int &vector_front()
{
	return niz[0];
}

int &vector_back()
{
	return niz[log-1];
}

int vector_size()
{
	return log;
}

}vektor;

int main()
{
	int init;
	cout << "upisi velicinu niza"<<endl;
	cin >> init;
	vektor *v = new vektor;
	v->vector_new(init);
	cout << "push, pop, velicina, front, back, kraj" << endl;
	string unos;
	cin >> unos;
	while (unos.compare("kraj") != 0)
	{
		if (unos.compare("push") == 0)
			v->vector_push_back();
		if (unos.compare("pop") == 0)
			cout<<v->vector_pop_back()<<endl;
		if (unos.compare("velicina") == 0)
			cout << v->vector_size()<<endl;
		if (unos.compare("front") == 0)
			cout << v->vector_front()<<endl;
		if (unos.compare("back") == 0)
			cout << v->vector_back()<<endl;
		cout << "push, pop, velicina, front, back, kraj" << endl;
		cin >> unos;
	}
	delete v;
	system("pause");
}