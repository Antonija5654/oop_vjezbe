#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int sibice = 21;
	int izvlacenje;
	while (true)
	{
		cout << "broj sibica je " << sibice << endl;
		
		//komp
		if (sibice == 1)
		{
			cout << "pobjedili ste" << endl;
			system("pause");
			return 0;
		}
		else if (sibice == 2)
		{
			izvlacenje = 1;
			sibice=sibice-izvlacenje;
		}
		else if (sibice == 3)
		{
			izvlacenje = 2;
			sibice = sibice - izvlacenje;
		}
		else if (sibice == 4)
		{
			izvlacenje = 3;
			sibice = sibice - izvlacenje;
		}
		else
		{
			izvlacenje = (rand() % 3) + 1;
			sibice = sibice - izvlacenje;
		}

		cout << "racunalo je izvuklo " << izvlacenje << " sibica" << endl;
		cout << "broj sibica je " << sibice << endl;
		
		//ja
		cout << "izvucite sibice ";
		cin >> izvlacenje;
		while (true)
		{
			if (izvlacenje < 4 && izvlacenje>0)
				break;
			else
			{
				cout << "broj nije u valjanom rasponu, izaberite 1, 2, ili 3" << endl;
				cin >> izvlacenje;
			}
		}
		if (sibice == 1)
		{
			while (true)
			{
				if (izvlacenje == 1)
				{
					cout << "racunalo je pobjedilo"<<endl;
					system("pause");
					return 0;
				}
				else
				{
					cout << "mozete izvuci samo 1 sibicu, upisite ponovo" << endl;
					cin >> izvlacenje;
				}
			}
		}
		if (sibice == 2)
		{
			while (true)
			{
				if (izvlacenje == 1 || izvlacenje == 2)
				{
					if (sibice-izvlacenje == 0)
					{
						cout << "racunalo je pobjedilo"<<endl;
						system("pause");
						return 0;
					}
					break;
				}
				else
				{
					cout << "mozete izvuci 1 ili 2 sibice, upisite ponovo" << endl;
					cin >> izvlacenje;
				}
			}
		}
		sibice = sibice - izvlacenje;
		if (sibice == 0)
		{
			cout << "racunalo je pobjedilo" << endl;
			system("pause");
			return 0;
		}
	}
}