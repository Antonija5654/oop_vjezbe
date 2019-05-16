#ifndef RPG_H
#define RPG_H
#include <string>
#include "VideoGame.h";
#include <vector>
using namespace std;

namespace oop
{
	class RPG :virtual public VideoGame
	{
		string type()
		{
			return "rpg";
		}
	};

	class DarkSouls :public RPG
	{
	private:
		vector<string> plat;
		string ime = "DarkSouls3";
	public:
		void izdvoji();

		vector<string> vrati_plat() { return plat; }

		~DarkSouls() {}
	};

	class Fallout4 :public RPG
	{
	private:
		vector<string> plat;
		string ime = "Fallout4";
	public:
		void izdvoji();

		vector<string> vrati_plat() { return plat; }

		~Fallout4() {}
	};
}
#endif