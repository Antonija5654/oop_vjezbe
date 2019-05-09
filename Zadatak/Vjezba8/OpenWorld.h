#ifndef OPENWORLD_H
#define OPENWORLD_H
#include <string>
#include "VideoGame.h";
using namespace std;

class OpenWorld :VideoGame
{
	string type()
	{
		return "open world";
	}
};

class Witcher3 :RPG, OpenWorld
{
private:
	string plat[];
public:
	string type()
	{
		return "open world rpg";
	}
};

#endif