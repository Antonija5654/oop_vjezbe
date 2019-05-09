#ifndef ACTION_H
#define ACTION_H
#include <string>
#include "VideoGame.h";
using namespace std;

class Action:VideoGame
{
	string type()
	{
		return "action";
	}
};

class TheLastOfUs2:Action
{
private:
	string plat[];
};

class GodOfWar:Action
{
private:
	string plat[];
};

#endif