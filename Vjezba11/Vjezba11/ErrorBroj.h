#ifndef ERRORBROJ_H
#define ERRORBROJ_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ErrorBroj : public XError
{
public:
	void ispisi(ofstream& dat)
	{
		cout << "Nije unesen broj" << endl;
		time_t t = time(NULL);
		string time = ctime(&t);
		dat << "Nije unesen broj  " << time << endl;
	}
};

#endif