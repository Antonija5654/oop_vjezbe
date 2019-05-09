#ifndef RPG_H
#define RPG_H
#include <string>
#include "VideoGame.h";
using namespace std;

class RPG :VideoGame
{
	string type()
	{
		return "rpg";
	}
};

class DarkSouls :RPG
{
private:
	string plat[];
};

class Fallout4 :RPG
{
private:
	string plat[];
};

#endif