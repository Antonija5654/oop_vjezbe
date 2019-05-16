#ifndef ACTION_H
#define ACTION_H
#include <string>
#include "VideoGame.h";
#include <vector>
using namespace std;

namespace oop
{

	class Action :virtual public VideoGame
	{
		string type()
		{
			return "action";
		}
	};

	class TheLastOfUs2 :public Action
	{
	private:
		vector<string> plat;
		string ime = "LastOfUs2";
	public:
		void izdvoji();

		vector<string> vrati_plat() { return plat; }

		~TheLastOfUs2() {}
	};

	class GodOfWar :public Action
	{
	private:
		vector<string> plat;
		string ime = "GodOfWar";
	public:
		void izdvoji();

		vector<string> vrati_plat() { return plat; }

		~GodOfWar() {}
	};
}
#endif