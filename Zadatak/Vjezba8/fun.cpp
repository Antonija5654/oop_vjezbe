#include <string>
#include <iostream>
#include <fstream>
#include "VideoGame.h";
#include "OpenWorld.h";
#include "Action.h";
#include "RPG.h";
#include "Counter.h";

void izdvoji()
{
	string platforma[] = { "PC", "PS4", "XBOX" };
	ofstream file;
	file.open("videogames.txt");
	if (file.fail())
	{
		cout << "nije otvorilo datoteku";
		return;
	}

}