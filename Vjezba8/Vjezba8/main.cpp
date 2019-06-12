#include <string>
#include <iostream>
#include "VideoGame.h";
#include "OpenWorld.h";
#include "Action.h";
#include "RPG.h";
#include "Counter.h";
using namespace oop;

VideoGame::~VideoGame() {}

int main()
{
	Counter c;
	VideoGame* v[] = { new Witcher3, new DarkSouls, new Fallout4, new TheLastOfUs2, new GodOfWar };
	size_t sz = sizeof v / sizeof v[0];
	for (unsigned i = 0; i < sz; ++i)
	{
		(*v[i]).izdvoji();
		c.provjeri(v[i]);
	}
	std::cout << "Najzastupljenija platforma: " << c.najcesca_plat() << endl;
	for (unsigned i = 0; i < sz; ++i)
		delete v[i];	system("pause");
}