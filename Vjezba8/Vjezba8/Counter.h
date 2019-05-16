#ifndef COUNTER_H
#define COUNTER_H
#include <string>
#include "VideoGame.h";
using namespace std;

namespace oop
{
	class Counter
	{
	private:
		int pc = 0, ps = 0, xbox = 0;
	public:
		void provjeri(VideoGame *v);

		string najcesca_plat();
	};
}
#endif