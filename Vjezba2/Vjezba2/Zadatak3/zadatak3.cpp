#include <iostream>
using namespace std;

typedef struct vektor {
	int *niz;
	int log, fiz;

vektor *vector_new(vektor *v, int init)
{
	vektor *v_novi = new vektor[init];
	v_novi->log = 0;
	v_novi->fiz = init;
	return v_novi;
}

void vector_delete(vektor *v)
{
	delete[] v->niz;
	delete[] v;
}

vektor *vector_push_back(vektor *v)
{
	if (v->log == v->fiz)
	{
		v = (vektor*)realloc(v, v->fiz * 2);
		v->fiz = v->fiz * 2;
	}
	int br;
	cout << "unesite broj" << endl;
	cin >> br;
	v->niz[v->log] = br;
	v->log++;
	return v;
}

int vector_pop_back(vektor *v)
{
	v->log--;
	return v->niz[v->log + 1];
}

int &vector_front(vektor *v)
{
	
}

}vektor;

int main()
{
	int init;
	cout << "upisi velicinu niza"<<endl;
	cin >> init;
}