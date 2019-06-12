#include <string>
#include <iostream>
#include <fstream>
#include "VideoGame.h";
#include "OpenWorld.h";
#include "Action.h";
#include "RPG.h";
#include "Counter.h";
#include<cstdlib>
using namespace oop;

void DarkSouls::izdvoji()
{
	ifstream file;
	file.open("videogames.txt");
	if (file.fail())
	{
		cout << "nije otvorilo datoteku";
		return;
	}
	string search = ime;
	string tmp2 = "";
	bool flag = 0;
	while (!file.eof())
	{
		string tmp = "";
		getline(file, tmp);
		for (int i = 0; i < search.size(); i++)
		{
			if (tmp[i] == search[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] == '#')
					tmp2 = "";
				else if (tmp[j] == ',')
				{
					plat.push_back(tmp2);
					tmp2 = "";
				}
				else
					tmp2 += tmp[j];
			}
			plat.push_back(tmp2);
		}

	}
	file.close();
}

void Fallout4::izdvoji()
{
	ifstream file;
	file.open("videogames.txt");
	if (file.fail())
	{
		cout << "nije otvorilo datoteku";
		return;
	}
	string search = ime;
	string tmp2 = "";
	bool flag = 0;
	while (!file.eof())
	{
		string tmp = "";
		getline(file, tmp);
		for (int i = 0; i < search.size(); i++)
		{
			if (tmp[i] == search[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] == '#')
					tmp2 = "";
				else if (tmp[j] == ',')
				{
					plat.push_back(tmp2);
					tmp2 = "";
				}
				else
					tmp2 += tmp[j];
			}
			plat.push_back(tmp2);
		}

	}
	file.close();
}

void Witcher3::izdvoji()
{
	ifstream file;
	file.open("videogames.txt");
	if (file.fail())
	{
		cout << "nije otvorilo datoteku";
		return;
	}
	string search = ime;
	string tmp2 = "";
	bool flag = 0;
	while (!file.eof())
	{
		string tmp = "";
		getline(file, tmp);
		for (int i = 0; i < search.size(); i++)
		{
			if (tmp[i] == search[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] == '#')
					tmp2 = "";
				else if (tmp[j] == ',')
				{
					plat.push_back(tmp2);
					tmp2 = "";
				}
				else
					tmp2 += tmp[j];
			}
			plat.push_back(tmp2);
		}

	}
	file.close();
}

void TheLastOfUs2::izdvoji()
{
	ifstream file;
	file.open("videogames.txt");
	if (file.fail())
	{
		cout << "nije otvorilo datoteku";
		return;
	}
	string search = ime;
	string tmp2 = "";
	bool flag = 0;
	while (!file.eof())
	{
		string tmp = "";
		getline(file, tmp);
		for (int i = 0; i < search.size(); i++)
		{
			if (tmp[i] == search[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] == '#')
					tmp2 = "";
				else if (tmp[j] == ',')
				{
					plat.push_back(tmp2);
					tmp2 = "";
				}
				else
					tmp2 += tmp[j];
			}
			plat.push_back(tmp2);
		}

	}
	file.close();
}

void GodOfWar::izdvoji()
{
	ifstream file;
	file.open("videogames.txt");
	if (file.fail())
	{
		cout << "nije otvorilo datoteku";
		return;
	}
	string search = ime;
	string tmp2 = "";
	bool flag = 0;
	while (!file.eof())
	{
		string tmp = "";
		getline(file, tmp);
		for (int i = 0; i < search.size(); i++)
		{
			if (tmp[i] == search[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] == '#')
					tmp2 = "";
				else if (tmp[j] == ',')
				{
					plat.push_back(tmp2);
					tmp2 = "";
				}
				else
					tmp2 += tmp[j];
			}
			plat.push_back(tmp2);
		}

	}
	file.close();
}

void Counter::provjeri(VideoGame *v)
{
	vector<string> plat = v->vrati_plat();
	for (int i = 0; i < plat.size(); i++)
	{
		if (plat[i].compare("PC") == 0)
			pc += 1;
		else if (plat[i].compare("PS4") == 0)
			ps += 1;
		else if (plat[i].compare("XBOX") == 0)
			xbox += 1;
	}
}

string Counter::najcesca_plat()
{
	if (pc > ps && pc > xbox)
		return "PC";
	else if (ps > pc && ps > xbox)
		return "PS4";
	else if (xbox > ps && xbox > pc)
		return "XBOX";
}