#ifndef ERRORNULL_H
#define ERRORNULL_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ErrorNull : public XError
{
public:
	void ispisi(ofstream& dat)
	{
		cout << "Dijeljenje s nulom" << endl;
		time_t t = time(NULL);
		string time = ctime(&t);
		dat << "Dijeljenje s nulom  " << time << endl;
	}
};

#endif