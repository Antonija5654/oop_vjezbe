#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <string>
using namespace std;

class VideoGame
{
public:
	virtual string type() = 0;
};

#endif