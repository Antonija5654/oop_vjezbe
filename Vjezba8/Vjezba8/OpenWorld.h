#ifndef OPENWORLD_H
#define OPENWORLD_H
#include <string>
#include "VideoGame.h";
#include "RPG.h";
#include <vector>
using namespace std;

namespace oop
{
	class OpenWorld :virtual public VideoGame
	{
		string type()
		{
			return "open world";
		}
	};

	class Witcher3 :public RPG, public  OpenWorld
	{
	private:
		vector<string> plat;
		string ime = "Witcher3";
	public:
		string type()
		{
			return "open world rpg";
		}

		void izdvoji();

		vector<string> vrati_plat() { return plat; }

		~Witcher3() {}
	};
}
#endif