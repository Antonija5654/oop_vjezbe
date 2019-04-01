#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct producent{
	string name, movie;
	int year;
}producent;

typedef struct {
	string ime;
	int br;
}provjera;

vector<string> pronadi(vector<producent> v, vector<provjera> p, vector<string> imena)
{
	int i, j;
	bool flag;
	provjera tmp;
	for (i = 0; i < v.size(); i++)
	{
		flag = true;
		for (j = 0; j < p.size(); j++)
		{
			if (v[i].name.compare(p[j].ime) == 0)
			{
				p[j].br++;
				flag = false;
			}
		}
		if (flag == true)
		{
			tmp.ime=v[i].name;
			tmp.br = 1;
			p.push_back(tmp);
		}
	}
	int max = 0;
	for (i = 0; i < p.size(); i++)
	{
		if (p[i].br > max)
			max = p[i].br;
	}
	for (i = 0; i < p.size(); i++)
	{
		if (p[i].br == max)
			imena.push_back(p[i].ime);
	}
	return imena;
}

int main()
{
	vector<producent> v;
	vector<provjera> p;
	vector<string> imena;
	producent tmp;
	string unos;
	while (unos.compare("kraj") != 0)
	{
		cout << "dodaj, kraj" << endl;;
		cin >> unos;
		if (unos.compare("dodaj") == 0)
		{
			cout << "ime" << endl;;
			cin >> tmp.name;
			cout << "ime filma" << endl;;
			cin >> tmp.movie;
			cout << "godina" << endl;;
			cin >> tmp.year;
			v.push_back(tmp);
		}
	}
	imena = pronadi(v, p, imena);
	int i;
	for (i = 0; i < imena.size(); i++)
		cout << imena[i]<<endl;
	system("pause");
}