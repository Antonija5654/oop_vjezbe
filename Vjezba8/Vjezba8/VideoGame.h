#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <string>
#include <vector>
using namespace std;

namespace oop
{
	class VideoGame
	{
	public:
		virtual string type() = 0;

		virtual void izdvoji() = 0;

		virtual vector<string> vrati_plat() = 0;

		virtual ~VideoGame() = 0;
	};
}
#endif