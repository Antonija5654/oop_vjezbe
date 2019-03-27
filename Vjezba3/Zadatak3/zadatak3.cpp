#include <iostream>
#include <string>
using namespace std;

string *popravi(string str, string *novi, int n)
{
	int i, br=0;
	for (i = 0; i < n; i++)
	{
		if (str[i]==' ')
		{
			cout << "test1" << endl;
			if (str[i + 1] == ',' || str[i + 2] == '.')
			{
				novi[br] = str[i=1];
				br++;
			}
			else
			{
				novi[br] = str[i];
				br++;
			}
		}
		else if (str[i] == ',' || str[i] == '.')
		{
			cout << "test2" << endl;
			if (str[i + 1] != ' ')
			{
				novi[br] = str[i];
				br++;
				novi[br] = ' ';
				br++;
			}
			else
			{
				novi[br] = str[i];
				br++;
			}
		}
		else
		{
			cout << "test3" << endl;
			novi[br] = str[i];
			br++;
		}
	}
	return novi;
}

int main()
{
	string str = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";
	string *novi=new string;
	int n = str.size();
	//novi = popravi(str, novi, n);
	int i;
	int m = novi->size();
	cout << m<<endl;
	for (i = 0; i < m; i++)
		cout << novi[i];
	system("pause");
}