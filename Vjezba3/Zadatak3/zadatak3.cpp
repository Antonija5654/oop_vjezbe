#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> popravi(string str, vector<char> novi)
{
	int i;
	for (i = 0; i < str.size(); i++)
	{
		cout << "OMEGALUL" << endl;
		if (str[i]==' ')
		{
			cout << "test1" << endl;
			if (str[i + 1] == ',' || str[i + 1] == '.')
			{
				novi.push_back(str[i + 1]);
			}
			else
			{
				novi.push_back(str[i]);
			}
		}
		else if (str[i] == ',' || str[i] == '.')
		{
			cout << "test2" << endl;
			if (str[i + 1] != ' ')
			{
				novi.push_back(' ');
			}
		}
		else
		{
			cout << "test3" << endl;
			novi.push_back(str[i]);
		}
	}
	return novi;
}

int main()
{
	string str = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";
	vector<char> novi;
	novi = popravi(str, novi);
	int i;
	for (i = 0; i < novi.size(); i++)
		cout << novi[i];
	system("pause");
}