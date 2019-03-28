#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> pretvori(vector<string> str, vector<string> novo)
{
	int i, j, m, br, brojac;
	char slovo;
	char tmp[1024];
	bool flag;
	for (i = 0; i < str.size(); i++)
	{
		flag = false;
		for (j = 0; j < str[i].size(); j++)
		{
			if (isdigit(str[i][j]))
				flag = true;
		}
		if (flag == true)
		{
			//2F8H4SF3
			brojac = 0;
			for (j = 0; j < str[i].size(); j++)
			{
				if (j == str[i].size() - 1)
				{
					if (isalpha(str[i][j]) && isalpha(str[i][j - 1]))
					{
						slovo = str[i][j];
						tmp[brojac] = slovo;
						brojac++;
					}
				}
				else
				{
					if (isdigit(str[i][j]) && isalpha(str[i][j + 1]))
					{
						br = str[i][j] - '0';
						slovo = str[i][j + 1];
						for (m = 0; m < br; m++)
						{
							tmp[brojac] = slovo;
							brojac++;
						}
					}
					else if (isalpha(str[i][j]) && isalpha(str[i][j - 1]))
					{
						slovo = str[i][j];
						tmp[brojac] = slovo;
						brojac++;
					}
				}
			}
			tmp[brojac] = '\0';
			novo.push_back(tmp);
		}
		else if (flag == false)
		{
			//AABFBBBBCC
			brojac = 0;
			for (j = 0; j < str[i].size(); j++)
			{
				if (j == 0)
				{
					slovo = str[i][j];
					br = 0;
					while (str[i][j] == slovo)
					{
						br++;
						j++;
					}
					if (br == 1)
					{
						tmp[brojac] = slovo;
						brojac++;
					}
					else
					{
						tmp[brojac] = br + '0';
						brojac++;
						tmp[brojac] = slovo;
						brojac++;
					}
				}
				else
				{
					slovo = str[i][j];
					br = 0;
					while (str[i][j] == slovo)
					{
						br++;
						j++;
					}
					if (br == 1)
					{
						tmp[brojac] = slovo;
						brojac++;
					}
					else
					{
						tmp[brojac] = br + '0';
						brojac++;
						tmp[brojac] = slovo;
						brojac++;
					}
				}
				j--;
			}
			tmp[brojac] = '\0';
			novo.push_back(tmp);
		}
	}
	return novo;
}

int main()
{
	int n, i=0, j;
	vector<string> str;
	vector<string> novo;
	string tmp;
	cout << "unesite n" << endl;
	cin >> n;
	while (i < n)
	{
		cout << "unesite string"<<endl;
		cin >> tmp;
		if (tmp.size() < 20)
		{
			for (j = 0; j < tmp.size(); j++)
			{
				if (islower(tmp[j]))
					tmp[j] = toupper(tmp[j]);
			}
			str.push_back(tmp);
			i++;
		}
	}
	novo = pretvori(str, novo);
	for (i = 0; i < novo.size(); i++)
		cout << novo[i] << endl;
	system("pause");
}